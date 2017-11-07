#ifndef __RECORD_SRV_PROC_H__
#define __RECORD_SRV_PROC_H__


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

#include "libsip.h"
#include "libxml/Packet.h"

#include "common/gbldef.inc"
#include "common/DBOper.h"

#include <vector>
#include <string>
#include <queue>

#include "record/record_info_mgn.inc"
#include "resource/resource_info_mgn.inc"

using namespace std;

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
    /* ¼��ҵ����Ϣ�ṹ�� */
    typedef struct _record_srv_msg_t
    {
        msg_type_t msg_type;                                /* ��Ϣ���� */
        char caller_id[MAX_ID_LEN + 4];                     /* �����û�ͳһ��� */
        char callee_id[MAX_ID_LEN + 4];                     /* �����û�ͳһ��� */
        int response_code;                                  /* ��Ӧ��Ϣ��,ֻ�л�Ӧ��Ϣ�� */
        char reasonphrase[MAX_128CHAR_STRING_LEN + 4];      /* ��Ӧ�Ĵ�����Ϣ��ֻ�л�Ӧ��Ϣ�� */
        int ua_dialog_index;                                /* ��Ӧdialog ������ֻ�лỰ����Ϣ�� */
        char msg_body[MAX_MSG_BODY_STRING_LEN + 4];         /* SIP ��ϢЯ������Ϣ�� */
        int msg_body_len;                                   /* SIP ��ϢЯ������Ϣ�峤�� */
        int cr_pos;                                         /* ��Ӧ�ĺ�����Դ������Ϣ */
    } record_srv_msg_t;

    /* ¼��ҵ����Ϣ���� */
    typedef std::deque <record_srv_msg_t*> record_srv_msg_queue;

    extern int record_bye_msg_proc(int cr_pos, int ua_dialog_index);
    extern int record_bye_response_msg_proc(int cr_pos, int ua_dialog_index, int response_code);
    extern int record_invite_response_msg_proc(int cr_pos, int ua_dialog_index, int response_code, char* msg_body, int msg_body_len);
    extern int record_srv_msg_add(msg_type_t msg_type, char* caller_id, char* callee_id, int response_code, char* reasonphrase, int ua_dialog_index, char* msg_body, int msg_body_len, int cr_pos);
    extern void record_srv_msg_free(record_srv_msg_t* record_srv_msg);
    extern int record_srv_msg_init(record_srv_msg_t** record_srv_msg);
    extern void record_srv_msg_list_clean();
    extern void record_srv_msg_list_free();
    extern int record_srv_msg_list_init();
    extern int record_srv_msg_proc(record_srv_msg_t* pRecordSrvMsg);
    extern void scan_record_srv_msg_list();
    extern int StartDeviceRecord(record_info_t* pProcRecordInfo);
    extern int StopAllProcRecordTask();
    extern int StopAllRecordTask(int sock);
    extern int StopDeviceRecord(int record_cr_index);
    extern int StopRecordTask(int sock, int record_cr_index);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __UDP_TL_H__ */