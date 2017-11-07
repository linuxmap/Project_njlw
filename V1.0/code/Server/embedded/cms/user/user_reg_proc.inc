#ifndef __USER_REG_PROC_H__
#define __USER_REG_PROC_H__


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

#include "user/user_info_mgn.inc"

#include <vector>
#include <string>
#include <queue>

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

    /* �û�ע����Ϣ�ṹ�� */
    typedef struct _user_reg_msg_t
    {
        char register_id[MAX_ID_LEN + 4];                   /* ͳһ���id */
        char login_ip[MAX_IP_LEN];                          /* ��¼��IP��ַ */
        int login_port;                                     /*  ��¼�Ķ˿� */
        char register_name[MAX_128CHAR_STRING_LEN + 4];     /* ��¼���û���*/
        int expires;                                        /* ��ʱʱ�� */
        int reg_info_index;                                 /* Э��ջ�û�ע������ */
    } user_reg_msg_t;

    /* �û�ע����Ϣ���� */
    typedef std::deque <user_reg_msg_t*> user_reg_msg_queue;

    extern int GetUserCfg(DBOper* pdboper, string strUserID, user_cfg_t& user_cfg);
    extern void scan_user_reg_msg_list(DBOper* pUser_Reg_dboper);
    extern void scan_user_unreg_msg_list(DBOper* pUser_Reg_dboper);
    extern int UserRefresh(user_info_t* pUserInfo, DBOper* pdboper);
    extern int UserReg(user_info_t* pUserInfo, user_cfg_t& user_cfg, DBOper* pdboper);
    extern int UserUnReg(user_info_t* pUserInfo, DBOper* pdboper);
    extern int UserUnRegAbnormal(user_info_t* pUserInfo, DBOper* pdboper);
    extern int user_reg_msg_add(char* user_id, char* login_ip, int login_port, char* register_name, int expires, int reg_info_index);
    extern void user_reg_msg_free(user_reg_msg_t* user_reg_msg);
    extern int user_reg_msg_init(user_reg_msg_t** user_reg_msg);
    extern void user_reg_msg_list_clean();
    extern void user_reg_msg_list_free();
    extern int user_reg_msg_list_init();
    extern int user_reg_msg_proc(user_reg_msg_t* pMsg, DBOper* pdboper);
    extern void user_unreg_msg_list_clean();
    extern int user_unreg_msg_proc(user_reg_msg_t* pMsg, DBOper* pdboper);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __UDP_TL_H__ */