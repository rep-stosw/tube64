#include <stdlib.h>

#include "defs.h"
#include "misc.h"

#include "allocator.h"

#include "DSEG3.h"

uintptr_t DSEG3;
uintptr_t DSEG4;

char *MINIBuf=NULL;

static char *DSEG3p=NULL;
static char *DSEG4p=NULL;

u32 FileSize(FILE *f)
{
 fseek(f,0,SEEK_END);
 u32 r=ftell(f);
 fseek(f,0,SEEK_SET);
 return r;
}

void LoadDSEG(void)
{
 FILE *f=fopen("DSEG3.bin","rb");
 if(!f)
 {
  printf("error!\n");
  exit(-1);
 }
 u32 s=FileSize(f);
 DSEG3p=(char*)Malloc(s+0x1000);                        //с учётом выравнивания
 DSEG3=(((uintptr_t)DSEG3p)+0x1000)&0xFFFFFFFFFFFFF000; //64-bit
 fread((void*)DSEG3,1,s,f);
 fclose(f);

 *(u32*)&startup_files[(44*0)+28]=(u32)(uintptr_t)&GlassMap;
 *(u32*)&startup_files[(44*1)+28]=(u32)(uintptr_t)&block_data;
 *(u32*)&startup_files[(44*2)+28]=(u32)(uintptr_t)&logo_data;
 *(u32*)&startup_files[(44*3)+28]=(u32)(uintptr_t)&logo;
 *(u32*)&startup_files[(44*3)+28+4]=(u32)(uintptr_t)&logo_end;
 *(u32*)&startup_files[(44*4)+28]=(u32)(uintptr_t)&palette;
 *(u32*)&startup_files[(44*5)+28]=(u32)(uintptr_t)&high_scores;
 *(u32*)&startup_files[(44*6)+28]=(u32)(uintptr_t)&tube_graphics;
 *(u32*)&startup_files[(44*7)+28]=(u32)(uintptr_t)&WScreen;
 *(u32*)&startup_files[(44*8)+28]=((u32)(uintptr_t)&WScreen)+0x48; //(u32)(uintptr_t)&VesaData;

 *(u32*)&array_list[2* 0]=(u32)(uintptr_t)&anim_order_1[0];
 *(u32*)&array_list[2* 1]=(u32)(uintptr_t)anim_order_2;
 *(u32*)&array_list[2* 2]=(u32)(uintptr_t)anim_order_3;
 *(u32*)&array_list[2* 3]=(u32)(uintptr_t)anim_order_4;
 *(u32*)&array_list[2* 4]=(u32)(uintptr_t)anim_order_5;
 *(u32*)&array_list[2* 5]=(u32)(uintptr_t)anim_order_6;
 *(u32*)&array_list[2* 6]=(u32)(uintptr_t)anim_order_7;
 *(u32*)&array_list[2* 7]=(u32)(uintptr_t)anim_order_8;
 *(u32*)&array_list[2* 8]=(u32)(uintptr_t)anim_order_9;
 *(u32*)&array_list[2* 9]=(u32)(uintptr_t)anim_order_10;
 *(u32*)&array_list[2*10]=(u32)(uintptr_t)anim_order_11;
 *(u32*)&array_list[2*11]=(u32)(uintptr_t)anim_order_12;
 *(u32*)&array_list[2*12]=(u32)(uintptr_t)anim_order_13;
 *(u32*)&array_list[2*13]=(u32)(uintptr_t)anim_order_14;
 *(u32*)&array_list[2*14]=(u32)(uintptr_t)anim_order_15;
 *(u32*)&array_list[2*15]=(u32)(uintptr_t)anim_order_16;
 *(u32*)&array_list[2*16]=(u32)(uintptr_t)anim_order_17;
 *(u32*)&array_list[2*17]=(u32)(uintptr_t)anim_order_18;
 *(u32*)&array_list[2*18]=(u32)(uintptr_t)anim_order_19;
 *(u32*)&array_list[2*19]=(u32)(uintptr_t)anim_order_20;
 *(u32*)&array_list[2*20]=(u32)(uintptr_t)anim_order_21;
 *(u32*)&array_list[2*21]=(u32)(uintptr_t)anim_order_22;
 *(u32*)&array_list[2*22]=(u32)(uintptr_t)anim_order_23;
 *(u32*)&array_list[2*23]=(u32)(uintptr_t)anim_order_24;
 *(u32*)&array_list[2*24]=(u32)(uintptr_t)anim_order_25;
 *(u32*)&array_list[2*25]=(u32)(uintptr_t)anim_order_26;
 *(u32*)&array_list[2*26]=(u32)(uintptr_t)anim_order_27;
 *(u32*)&array_list[2*27]=(u32)(uintptr_t)anim_order_28;
 *(u32*)&array_list[2*28]=(u32)(uintptr_t)anim_order_29;
 *(u32*)&array_list[2*29]=(u32)(uintptr_t)anim_order_30;
 *(u32*)&array_list[2*30]=(u32)(uintptr_t)anim_order_31;
 *(u32*)&array_list[2*31]=(u32)(uintptr_t)anim_order_32;
 *(u32*)&array_list[2*32]=(u32)(uintptr_t)anim_order_33;
 *(u32*)&array_list[2*33]=(u32)(uintptr_t)anim_order_34;
 *(u32*)&array_list[2*34]=(u32)(uintptr_t)anim_order_35;
 *(u32*)&array_list[2*35]=(u32)(uintptr_t)anim_order_36;
 *(u32*)&array_list[2*36]=(u32)(uintptr_t)anim_order_37;
 *(u32*)&array_list[2*37]=(u32)(uintptr_t)anim_order_38;

 f=fopen("DSEG4.bin","rb");
 if(!f)
 {
  printf("error!\n");
  exit(-1);
 }
 s=FileSize(f);
 DSEG4p=(char*)Malloc(s+0x1000);                        //с учётом выравнивания
 DSEG4=(((uintptr_t)DSEG4p)+0x1000)&0xFFFFFFFFFFFFF000; //64-bit
 fread((void*)DSEG4,1,s,f);
 fclose(f);

 MINIBuf=(char*)Calloc(44*2,1);
}

void FreeDSEG(void)
{
 if(DSEG3p)Free(DSEG3p);
 if(DSEG4p)Free(DSEG4p);
 if(MINIBuf)Free(MINIBuf);
}

