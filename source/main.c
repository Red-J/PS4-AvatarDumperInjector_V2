#include "ps4.h"
#include "kernel_utils.h"

void inject_avatar(char *drive) 
{
  char i_src_path[256];
  char i_dst_path[256];
	
  char back_path[256]; 
  char usbd[256];
  char msg[256]; 
	

	SceUserServiceLoginUserIdList userIdList;
	userIdList = getUserIDList();
	for (int i = 0; i < SCE_USER_SERVICE_MAX_LOGIN_USERS; i ++) 
	{
		if (userIdList.userId[i] != -1 && userIdList.userId[i] != 0) 
		{

			
			sprintf(i_src_path, "/mnt/usb%s/Avatar_Inject",drive);
			//systemMessage(i_src_path);
  			sprintf(i_dst_path, "/system_data/priv/cache/profile/0x%08X",userIdList.userId[i]);
			
			if (dir_exists(i_src_path))
				{ 
				sprintf(usbd,"Avatar data detected on usb%s\n Copying data...Please wait...",drive);
				systemMessage(usbd);
				
				sprintf(back_path, "/mnt/usb%s/Avatar_Backup_user_%s",drive,getUserName(userIdList.userId[i]));
				copy_Dir(i_dst_path,back_path);
				systemMessage("Avatar backup completed!");
				
  				copy_Dir(i_src_path, i_dst_path);
				sprintf(msg, "Avatar injection completed for %s!",getUserName(userIdList.userId[i]));
				systemMessage(msg);
				systemMessage("You can now reboot your PS4 or change the connected user");
				}
		}
	}
}

int _main(struct thread *td) {
	initKernel();
	initLibc();
 initPthread();

  uint64_t fw_version = get_fw_version();
  jailbreak(fw_version);
	//syscall(11,patcher,td);
	initSysUtil();
	
	systemMessage("Welcome to Avatar Injector v2.0\nby Red-J");

  char dirtest[256];
  int source_folder = -1;
  
  int row = 0;
  while (source_folder == -1) {
    sceKernelUsleep(100 * 1000);
    if (row >= 60) {
	systemMessage("No data detected.\n\nPlease insert Usb key with \"Avatar_Inject\" folder.");
 
      row = 0;
    } else {
      row += 1;
    }
    sprintf(dirtest, "/mnt/usb%i/Avatar_Inject/.dirtest", row / 10);
    source_folder = open(dirtest, O_WRONLY | O_CREAT | O_TRUNC, 0777);
  }

  unlink(dirtest);
  close(source_folder);

  char usbnum[16];
  sprintf(usbnum, "%i", row / 10);

	inject_avatar(usbnum);
	return 0;
}
