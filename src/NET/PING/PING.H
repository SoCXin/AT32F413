/********************************** (C) COPYRIGHT *********************************
* File Name          : CH561PING.H
* Author             : WCH
* Version            : V1.0
* Date               : 2017/3/8
* Description        : Define for PING.C
**********************************************************************************/
#ifndef __CH561PINGINC_H__
#define __CH561PINGINC_H__
//=================================================================================
#define DEBUG                        1            // 调试------------波特率115200


#define ICMP_SOKE_CON                0
#define ICMP_SEND_ERR                1
#define ICMP_SEND_SUC                2
#define ICMP_RECV_ERR                3
#define ICMP_RECV_SUC                4
#define ICMP_UNRECH                  5
#define ICMP_REPLY                   6
#define ICMP_REPLY_SUC               7
#define ICMP_KEEP_NO                10


#define ICMP_HEAD_TYPE               8
#define ICMP_HEAD_REPLY              0
#define ICMP_HEAD_CODE               0
#define ICMP_HEAD_ID                 512
#define ICMP_HEAD_SEQ                100
#define ICMP_DATA_BYTES              32

/*ICMP报头字段数据结构*/
typedef struct _icmphdr 
{
    UINT8   i_type;                 /* ICMP报文类型 */
    UINT8   i_code;                 /* 该类型中的代码号 */
    UINT16  i_cksum;                /* 校验和 */ 
    UINT16  i_id;                   /* 惟一的标识符 */
    UINT16  i_seq;                  /* 序列号 */
    UINT8   i_data[32];
}IcmpHeader,*IcmpHead;

extern UINT8  IcmpSuc;
extern UINT32 TimeCount;

/* CH561相关定义 */                                                                   
extern UINT8 MACAddr[6];                                                            /* MAC地址 */ 
extern const UINT8 IPAddr[4];                                                       /* IP地址 */ 
extern const UINT8 GWIPAddr[4];                                                     /* 网关 */
extern const UINT8 IPMask[4];                                                       /* 子网掩码 */ 
extern const UINT8 DestIP[4];
extern const UINT8 IPRawProto;                                                      /* IP包协议类型 */


void CH561NET_PINGCmd( void );                                                      /* 查询状态，执行子命令 */


void CH561NET_PINGInit( void );                                                     /* 561初始化 */

void InitPing( void );

void InitParameter( void );

void Respond_Ping( UINT8 *pDat );

void mStopIfError( UINT8 iError );

void CH561NET_HandleGloableInt( void );

void CH561NET_PINGSendData( UINT8 *PSend, UINT32 Len,UINT8 index );

void CH561NET_IcmpRecvData( UINT32 len, UINT8 *pDat );
#endif    
