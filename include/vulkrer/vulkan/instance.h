#ifndef VULKRER_INSTANCE_H
#define VULKRER_INSTANCE_H

struct vulkrer_instance;

struct vulkrer_instance *vulkrer_instance_create();

void vulkrer_instance_destroy(struct vulkrer_instance **instance);

#endif
