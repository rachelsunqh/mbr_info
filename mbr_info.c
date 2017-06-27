/*********************************************************************
* fun: MBR PART  INFO
*
*  <sqhxhg@163.com>
*
**********************************************************************/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define GRUB_PACKED __attribute__ ((packed))
/* The signature.  */
#define GRUB_PC_PARTITION_SIGNATURE		0xaa55

/* This is not a flag actually, but used as if it were a flag.  */
#define GRUB_PC_PARTITION_TYPE_HIDDEN_FLAG	0x10

/* DOS partition types.  */
#define GRUB_PC_PARTITION_TYPE_NONE		0
#define GRUB_PC_PARTITION_TYPE_FAT12		1
#define GRUB_PC_PARTITION_TYPE_FAT16_LT32M	4
#define GRUB_PC_PARTITION_TYPE_EXTENDED		5
#define GRUB_PC_PARTITION_TYPE_FAT16_GT32M	6
#define GRUB_PC_PARTITION_TYPE_NTFS	        7
#define GRUB_PC_PARTITION_TYPE_FAT32		0xb
#define GRUB_PC_PARTITION_TYPE_FAT32_LBA	0xc
#define GRUB_PC_PARTITION_TYPE_FAT16_LBA	0xe
#define GRUB_PC_PARTITION_TYPE_WIN95_EXTENDED	0xf
#define GRUB_PC_PARTITION_TYPE_PLAN9            0x39
#define GRUB_PC_PARTITION_TYPE_LDM		0x42
#define GRUB_PC_PARTITION_TYPE_EZD		0x55
#define GRUB_PC_PARTITION_TYPE_MINIX		0x80
#define GRUB_PC_PARTITION_TYPE_LINUX_MINIX	0x81
#define GRUB_PC_PARTITION_TYPE_LINUX_SWAP	0x82
#define GRUB_PC_PARTITION_TYPE_EXT2FS		0x83
#define GRUB_PC_PARTITION_TYPE_LINUX_EXTENDED	0x85
#define GRUB_PC_PARTITION_TYPE_VSTAFS		0x9e
#define GRUB_PC_PARTITION_TYPE_FREEBSD		0xa5
#define GRUB_PC_PARTITION_TYPE_OPENBSD		0xa6
#define GRUB_PC_PARTITION_TYPE_NETBSD		0xa9
#define GRUB_PC_PARTITION_TYPE_HFS		0xaf
#define GRUB_PC_PARTITION_TYPE_GPT_DISK		0xee
#define GRUB_PC_PARTITION_TYPE_LINUX_RAID	0xfd

/* The partition entry.  */
struct grub_msdos_partition_entry
{
  /* If active, 0x80, otherwise, 0x00.  */
  unsigned char flag;

  /* The head of the start.  */
  unsigned char start_head;

  /* (S | ((C >> 2) & 0xC0)) where S is the sector of the start and C
     is the cylinder of the start. Note that S is counted from one.  */
  unsigned char start_sector;

  /* (C & 0xFF) where C is the cylinder of the start.  */
  unsigned char start_cylinder;

  /* The partition type.  */
  unsigned char type;

  /* The end versions of start_head, start_sector and start_cylinder,
     respectively.  */
  unsigned char end_head;
  unsigned char end_sector;
  unsigned char end_cylinder;

  /* The start sector. Note that this is counted from zero.  */
  unsigned int start;

  /* The length in sector units.  */
  unsigned int length;
} GRUB_PACKED;

/* The structure of MBR.  */
struct grub_msdos_partition_mbr
{
  /* The code area (actually, including BPB).  */
  unsigned char code[446];

  /* Four partition entries.  */
  struct grub_msdos_partition_entry entries[4];

  /* The signature 0xaa55.  */
  unsigned short signature;
} GRUB_PACKED;

void type_info(unsigned char type_flag,unsigned char *type)
{
	switch(type_flag){
		case GRUB_PC_PARTITION_TYPE_FAT12:
			strcpy(type,"fat12");
			break;

               case GRUB_PC_PARTITION_TYPE_FAT16_LT32M:
                        strcpy(type,"fat16_lt32m");
			break;
	
               case GRUB_PC_PARTITION_TYPE_EXTENDED:
			strcpy(type,"extended");
			break;

               case GRUB_PC_PARTITION_TYPE_FAT16_GT32M:
			strcpy(type,"fat16_gt32m");
			break;

               case GRUB_PC_PARTITION_TYPE_NTFS:
			strcpy(type,"ntfs");
			break;

               case GRUB_PC_PARTITION_TYPE_FAT32:
                        strcpy(type,"fat32");
			break;
 			
               case GRUB_PC_PARTITION_TYPE_FAT32_LBA:
			strcpy(type,"fat32_lba");
			break;

               case GRUB_PC_PARTITION_TYPE_FAT16_LBA:
			strcpy(type,"fat16_lba");
			break;

               case GRUB_PC_PARTITION_TYPE_WIN95_EXTENDED:
			strcpy(type,"win95_extended");
			break;

               case GRUB_PC_PARTITION_TYPE_PLAN9:
			strcpy(type,"plan9");
			break;

               case GRUB_PC_PARTITION_TYPE_LDM:
			strcpy(type,"ldm");
			break;

               case GRUB_PC_PARTITION_TYPE_EZD:
			strcpy(type,"ezd");
			break;

               case GRUB_PC_PARTITION_TYPE_MINIX: 

			strcpy(type,"minix");
			break;
               case GRUB_PC_PARTITION_TYPE_LINUX_MINIX:

			strcpy(type,"linux_minix");
			break;
               case GRUB_PC_PARTITION_TYPE_LINUX_SWAP:
			strcpy(type,"linux_swap");
			break;
         
	      case GRUB_PC_PARTITION_TYPE_EXT2FS:
			strcpy(type,"ext2fs");
			break;
      
              case GRUB_PC_PARTITION_TYPE_LINUX_EXTENDED:

			strcpy(type,"extended");
			break;
               case GRUB_PC_PARTITION_TYPE_VSTAFS:
			strcpy(type,"vstafs");
			break;
               case GRUB_PC_PARTITION_TYPE_FREEBSD:

			strcpy(type,"freebsd");
			break;
               case GRUB_PC_PARTITION_TYPE_OPENBSD:
			strcpy(type,"openbsd");
			break;
               case GRUB_PC_PARTITION_TYPE_NETBSD:
			strcpy(type,"netbsd");
			break;

               case GRUB_PC_PARTITION_TYPE_HFS: 
            

			strcpy(type,"hfs");
			break;
               case GRUB_PC_PARTITION_TYPE_GPT_DISK:
			strcpy(type,"gpt_disk");
			break;
               
		case GRUB_PC_PARTITION_TYPE_LINUX_RAID:

			strcpy(type,"linux_raid");
			break;

		default:
			
			strcpy(type,"none");
			break;
	}
	

	return;
}
static void mbr_info(struct grub_msdos_partition_mbr *mbr)
{
    int i = 0;
    unsigned char info[32];
    memset(info,0,sizeof(info));    
    for(i = 0;i < 4;i++){
	printf("\tPART:%d\n",i);
        printf("\t\tflag:%02x\n",mbr->entries[i].flag);
        type_info(mbr->entries[i].type,info);	
	printf("\t\tType flag:%04x:%s\n",mbr->entries[i].type,info);
	printf("\t\tstart:0x%8x\n",mbr->entries[i].start);
	printf("\t\tlength:0x%8x\n",mbr->entries[i].length);
        printf("\t\tstart_head:0x%08x\n",mbr->entries[i].start_head);
        printf("\t\tend_head:0x%08x\n",mbr->entries[i].end_head);
        printf("\t\tstart_sector:0x%08x\n",mbr->entries[i].start_sector);	
        printf("\t\tend_sector:0x%08x\n",mbr->entries[i].end_sector);
        printf("\t\tstart_cylinder:0x%08x\n",mbr->entries[i].start_cylinder);
        printf("\t\tend_cylinder:0x%08x\n",mbr->entries[i].end_cylinder);
    }
	
       return;
}
int main(int argc,char *argv[])
{
    struct grub_msdos_partition_mbr mbr;	
    int fd = 0,ret = 0;
   
    memset(&mbr,0,sizeof(struct grub_msdos_partition_mbr));

    if(2 != argc){
	printf("\t%s [disk.img]\n",__func__);
	return -1;
    }

    fd = open(argv[1],O_RDONLY);
    if(0 > fd){
        printf("\t Please input valid file name\n");
	return fd;
    }
  
    ret = read(fd,&mbr,sizeof(struct grub_msdos_partition_mbr));
    if(ret != sizeof(struct grub_msdos_partition_mbr)){
       printf("The file's size should > 512 BYTES\n");	
       return -2;
    }

    if(GRUB_PC_PARTITION_SIGNATURE != mbr.signature){	
        printf("\t The file is not an bootable image!\n");
	return -3;
    }

    mbr_info(&mbr);

    close(fd);
    fd = 0;

    return 0;
}

