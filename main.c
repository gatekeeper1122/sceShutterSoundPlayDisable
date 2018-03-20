
#include <psp2/kernel/modulemgr.h>
#include <taihen.h>

static SceUID g_hooks[1] = {-1};


static tai_hook_ref_t sceShutterSoundPlayDisable_hook;
static int sceShutterSoundPlayDisable_patched(uint32_t soundType){

	return 0;

}





void _start() __attribute__ ((weak, alias("module_start")));

int module_start(SceSize args, void *argp){


	g_hooks[0] = taiHookFunctionImport(
					&sceShutterSoundPlayDisable_hook, 
					TAI_MAIN_MODULE, 
					TAI_ANY_LIBRARY,
					0x7FFB6D79, 
					sceShutterSoundPlayDisable_patched
					);


	return SCE_KERNEL_START_SUCCESS;
}

int module_stop(SceSize args, void *argp){

	if (g_hooks[0] >= 0) taiHookRelease(g_hooks[0], sceShutterSoundPlayDisable_hook);

	return SCE_KERNEL_STOP_SUCCESS;
}
