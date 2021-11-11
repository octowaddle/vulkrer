#include <vulkrer/vulkan/instance.h>
#include <stdio.h>

int main() {
    struct vulkrer_instance *instance = vulkrer_instance_create();
    vulkrer_instance_destroy(&instance);
    printf("success!\n");
}
