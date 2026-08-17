/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2013        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control module to the FatFs module with a defined API.        */
/*-----------------------------------------------------------------------*/

#include "diskio.h"		/* FatFs lower layer API */
#include "w25q64.h"
#include "device.h"
#include "spi.h"
#include "board.h"


#include "diskio.h"
#include "ff.h"
#include "ffconf.h"
#include "integer.h"

#define FLASH_SECTOR_SIZE      512
#define FLASH_BLOCK_SIZE       8
#define FLASH_SECTOR_COUNT     2048*8   //8M(8388608)/4096(FLASH_SECTOR_COUNT)

DSTATUS disk_initialize (BYTE pdrv)
{
	if(pdrv != 0) return STA_NOINIT;
	return 0;
}

DSTATUS disk_status (BYTE pdrv)
{ 
	if(pdrv != 0) return STA_NOINIT;
	return 0;
} 

DRESULT disk_read (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE *buff,		/* Data buffer to store read data */
	DWORD sector,	/* Sector address (LBA) */
	UINT count		/* Number of sectors to read (1..128) */
)
{
	uint8_t res=0;
    if (!count)return RES_PARERR;
	switch(pdrv)
	{
		case 0:
			for(;count>0;count--)
			{
				w25q64_read(mySPI_BASE, sector*FLASH_SECTOR_SIZE, FLASH_SECTOR_SIZE, buff);
				sector++;
				buff+=FLASH_SECTOR_SIZE;
			}
			res=0;
			break;
		default:
			res=1; 
	}
	if(res==0x00)return RES_OK;
    else return RES_ERROR;	   
}




DRESULT disk_write (
	BYTE pdrv,			/* Physical drive nmuber (0..) */
	const BYTE *buff,	/* Data to be written */
	DWORD sector,		/* Sector address (LBA) */
	UINT count			/* Number of sectors to write (1..128) */
)
{
	uint8_t res=0;
    if (!count)return RES_PARERR;
	switch(pdrv)
	{
		case 0:
			for(;count>0;count--)
			{										    
				flash_write(mySPI_BASE, sector*FLASH_SECTOR_SIZE, FLASH_SECTOR_SIZE, buff);
				sector++;
				buff+=FLASH_SECTOR_SIZE;
			}
			res=0;
			break;
		default:
			res=1; 
	}

	if(res == 0x00)return RES_OK;
    else return RES_ERROR;	
}

DRESULT disk_ioctl (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE cmd,		/* Control code */
	void *buff		/* Buffer to send/receive control data */
)
{
	DRESULT res;						  			     
 if(pdrv==0)
	{
	    switch(cmd)
	    {
		    case CTRL_SYNC:
				res = RES_OK; 
		        break;	 
		    case GET_SECTOR_SIZE:
		        *(WORD*)buff = FLASH_SECTOR_SIZE;
		        res = RES_OK;
		        break;	 
		    case GET_BLOCK_SIZE:
		        *(WORD*)buff = FLASH_BLOCK_SIZE;
		        res = RES_OK;
		        break;	 
		    case GET_SECTOR_COUNT:
		        *(DWORD*)buff = FLASH_SECTOR_COUNT;
		        res = RES_OK;
		        break;
		    default:
		        res = RES_PARERR;
		        break;
	    }
	}

 else res=RES_ERROR;
    return res;
}


DWORD get_fattime (void)
{				 
	return 0;
}















