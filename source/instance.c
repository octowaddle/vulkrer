#define VULKRER_INCLUDE_EXTERNAL

#include <vulkrer/vulkan/instance.h>
#include <vulkrer/common.h>

struct vulkrer_instance {
    VkInstance handle;
};

// TODO Enable validation layers when requested.
// TODO Enable extensions required for the window surfce.
// TODO Properly set application and engine versions.
// TODO Write errors somewhere (stderr, file, ...).
struct vulkrer_instance *vulkrer_instance_create() {
    struct vulkrer_instance *instance = malloc(sizeof *instance);

    if (instance != NULL) {
        const VkApplicationInfo application_info = {
            .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
            .pNext = NULL,
            .pApplicationName = "Vulkrer",
            .applicationVersion = VK_MAKE_VERSION(0, 0, 0),
            .pEngineName = "Vulkrer",
            .engineVersion = VK_MAKE_VERSION(0, 0, 0),
            .apiVersion = VK_API_VERSION_1_0
        };

        const VkInstanceCreateInfo instance_create_info = {
            .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
            .pNext = NULL,
            .flags = 0,
            .pApplicationInfo = &application_info,
            .enabledLayerCount = 0,
            .ppEnabledLayerNames = NULL,
            .enabledExtensionCount = 0,
            .ppEnabledExtensionNames = NULL
        };

        const VkResult result = vkCreateInstance(&instance_create_info, NULL, &(instance->handle));

        if (result != VK_SUCCESS) {
            return NULL;
        }
    }

    return instance;
}

void vulkrer_instance_destroy(struct vulkrer_instance **instance) {
    assert(instance != NULL);
    assert(*instance != NULL);
    assert((*instance)->handle != VK_NULL_HANDLE);

    vkDestroyInstance((*instance)->handle, NULL);
    free(*instance);

    *instance = NULL;
}
