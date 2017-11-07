/******************************************************************************

                  ��Ȩ���� (C), 2001-2013, ������Ѷ�������޹�˾

 ******************************************************************************
  �� �� ��   : udp_tl.h
  �� �� ��   : ����
  ��    ��   : yanghaifeng
  ��������   : 2013��4��1��
  ����޸�   :
  ��������   : udp_tl.c ��ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2013��4��1��
    ��    ��   : yanghaifeng
    �޸�����   : �����ļ�

******************************************************************************/
#ifndef __UDP_TL_H__
#define __UDP_TL_H__

//modified by chenyu 130522
#ifdef WIN32

#ifdef EV9000SIP_EXPORTS  
#define EV9000SIP_API    __declspec(dllexport) 
#else  
#define EV9000SIP_API    __declspec(dllimport) 
#endif

#else
#define EV9000SIP_API    extern
#endif //end WIN32

/*----------------------------------------------*
 * ����ͷ�ļ�                                   *
 *----------------------------------------------*/
#include <sys/types.h>
#ifdef WIN32
#include <winsock2.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#endif


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

    /*----------------------------------------------*
     * �ⲿ����˵��                                 *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * �ⲿ����ԭ��˵��                             *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * �ڲ�����ԭ��˵��                             *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * ȫ�ֱ���                                     *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * ģ�鼶����                                   *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * ��������                                     *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * �궨��                                       *
     *----------------------------------------------*/

    /* sip�������߳̽ṹ�� */
    typedef struct _run_thread_t
    {
        osip_thread_t* thread;
        int         th_exit;
    } run_thread_t;

    /* ����sip��Ϣ��udp�߳̽ṹ��*/
    typedef struct _udp_tl_t
    {
        int in_port;
        int in_socket;
        int out_port;
        int out_socket;
        osip_thread_t* thread;
        int th_exit;
    } udp_tl_t;

    /* ����sip��Ϣ��udp�̶߳��� */
    typedef struct udp_tl_list_t
    {
        osip_list_t*    udp_tl_list;
    } udp_tl_list_t;

    extern int send_message_using_udp(osip_transaction_t* trans, osip_message_t* sip , char* host , int port , int out_socket);
    extern int send_message_using_tcp(osip_message_t* sip, char* host, int port, int out_socket);
    EV9000SIP_API int SIP_UASStartUdpReceive(int local_port);
    EV9000SIP_API int SIP_UACStartUdpReceive(int* local_port);
    extern void* sip_stack_run_thread_execute(void* p);
    extern void* sip_app_run_thread_execute(void* p);
    extern void sip_run_thread_free(run_thread_t* run);
    extern int sip_run_thread_init(run_thread_t** run);
    extern int sip_run_thread_start();
    extern void  sip_run_thread_stop();
    EV9000SIP_API int  SIP_StopUdpReceive(int local_port);
    extern void SIP_StopAllUdpReceive();
    extern void udp_list_free();
    extern int udp_list_init();
    extern int udp_tl_execute(udp_tl_t* udp, osip_t* recv_cell, osip_t* recv_msg_cell, osip_t* send_msg_cell, int sec_max, int usec_max, int max_analysed);
    extern void udp_tl_free(udp_tl_t* udp);
    extern int udp_tl_init(udp_tl_t** udp, int in_port, int out_port);
    extern int udp_tl_start(udp_tl_t* udp);
    extern int udp_tl_stop(udp_tl_t* udp);
    extern void* udp_tl_thread(void* ptr);
    extern int udp_transport_thread_start(int* local_port);
    extern int udp_transport_thread_start_by_port(int local_port);
    extern int udp_transport_thread_stop(int local_port);
    extern int get_socket_by_port(int port);
    EV9000SIP_API void SIP_ShowSIPStackTransactionSize(int sock);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __UDP_TL_H__ */