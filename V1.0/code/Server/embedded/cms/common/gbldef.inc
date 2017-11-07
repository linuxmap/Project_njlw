#ifndef _GBL_DEF_H_
#define _GBL_DEF_H_

#include "EV9000_InnerDef.h"
#include "EV9000_ErrCodeDef.h"
#include "EV9000_ExtDef.h"
#include "EV9000_AlarmTypeDef.h"
#include "InnerProtocolDef.h"

#define SYS_VERSION ("1.01")
#if defined(__DATE__) && defined(__TIME__)
static const char server_built[] = __DATE__ " " __TIME__;
#else
static const char server_built[] = "unknown";
#endif

extern int g_Language;  /* ���ԣ�0:���ģ�1:Ӣ�ģ�Ĭ������ */

#define DECS(X) 1

#define IN
#define OUT

/* IP��ַ���� */
typedef enum _ip_addr_type_t
{
    IP_ADDR_VIDEO,                 /* ��Ƶ����ַ */
    IP_ADDR_DEVICE,                /* �豸����ַ */
    IP_ADDR_MGMT,                  /* ��������ַ��SXר�� */
    IP_ADDR_NULL
} ip_addr_type_t;

/* д���׼�����豸��ʱ���Ĵ���ԭ�� */
typedef enum _device_error_reason_type_t
{
    DEVICE_ERROR_REASON_NOT_FOUND,
    DEVICE_ERROR_REASON_IP_CONFLICT,
    DEVICE_ERROR_REASON_NULL
} device_error_reason_type_t;

/* ��Ϣ���� */
typedef enum _msg_type_t
{
    MSG_REGISTER,
    MSG_REGISTER_RESPONSE,
    MSG_INVITE,
    MSG_INVITE_RESPONSE,
    MSG_CANCEL,
    MSG_ACK,
    MSG_BYE,
    MSG_BYE_RESPONSE,
    MSG_INFO,
    MSG_INFO_RESPONSE,
    MSG_MESSAGE,
    MSG_MESSAGE_RESPONSE,
    MSG_SUBSCRIBE,
    MSG_SUBSCRIBE_RESPONSE,
    MSG_NOTIFY,
    MSG_NOTIFY_RESPONSE,
    MSG_TYPE_NULL
} msg_type_t;

/* XML ��Ϣ���� */
typedef enum _xml_type_t
{
    XML_CONTROL_DEVICECONTROL,           /* �豸���� */
    XML_CONTROL_DEVICECONFIG,            /* �豸���� */
    XML_CONTROL_SETDEVICEVIDEOPARAM,     /* ����ǰ��ͼ����� */
    XML_CONTROL_REQUESTIFRAMDATA,        /* ����I֡*/
    XML_CONTROL_AUTOZOOMIN,              /* ����Ŵ�*/
    XML_CONTROL_SETDEVICEXYPARAM,        /* ����ǰ�˾�γ�Ȳ��� */
    XML_CONTROL_EXECUTEPRESET,           /* ִ��Ԥ��λ */
    XML_QUERY_CATALOG,                   /* ��ѯ�豸Ŀ¼ */
    XML_QUERY_DEVICEINFO,                /* ��ѯ�豸��Ϣ */
    XML_QUERY_DEVICESTATUS,              /* ��ѯ�豸״̬ */
    XML_QUERY_DEVICECONFIG,              /* ��ѯ�豸���� */
    XML_QUERY_RECORDINFO,                /* ��ѯ�豸¼����Ϣ */
    XML_QUERY_USERCONFIG,                /* �û����û�ȡ */
    XML_QUERY_DEVICEGROUP,               /* �߼��豸������Ϣ */
    XML_QUERY_USERDEVICEGROUP,           /* �߼��豸���·�����Ϣ */
    XML_QUERY_DEVICEMAPGROUP,            /* �߼��豸����ӳ���ϵ */
    XML_QUERY_USERDEVICEMAPGROUP,        /* �߼��豸���·���ӳ���ϵ */
    XML_QUERY_SERVERID,                  /* ��ѯ������ID */
    XML_QUERY_POLLCONFIG,                /* �û���ѯ��Ѳ */
    XML_QUERY_POLLACTION_CONFIG,         /* �û���ѯ��Ѳ���� */
    XML_QUERY_PLANCONFIG,                /* �û���ѯԤ�� */
    XML_QUERY_PLANACTION_CONFIG,         /* �û���ѯԤ������ */
    XML_QUERY_CRUISE_CONFIG,             /* �û���ѯѲ�� */
    XML_QUERY_CRUISE_ACTION_CONFIG,      /* �û���ѯѲ������ */
    XML_QUERY_DEVICEVIDEOPARAM,          /* ��ȡǰ��ͼ����� */
    XML_QUERY_DEVICEPRESET,              /* ��ȡǰ��Ԥ��λ */
    XML_QUERY_GETDBIP,                   /* ��ȡ���ݿ�IP��ַ */
    XML_QUERY_TOPOLOGYPHYDEVICE,         /* ��ȡ���������豸���ñ� */
    XML_QUERY_GETPRESET,                 /* ��ȡԤ��λ���� */
    XML_QUERY_CHANNELSTATUS,             /* ��ȡ������ͨ��״̬ */
    XML_QUERY_WEBINTERFACECONFIG,        /* ��ȡ URL��Ϣ */
    XML_QUERY_ALARMRECORD,               /* ��ȡ������Ϣ */
    XML_QUERY_ONLINEUSER,                /* ��ȡ�����û���Ϣ */
    XML_QUERY_TSUINFO,                   /* ��ȡTCP��ʽ����µ�IP��ַ�Ͷ˿ں� */
    XML_QUERY_DATA_VALUE,                /* ��ȡǰ�˵�λ����ֵ */
    XML_QUERY_LABEL_RECORD,              /* ��ȡ��ǩ¼������ */
    XML_NOTIFY_ALARM,                    /* �澯֪ͨ */
    XML_NOTIFY_KEEPLIVE,                 /* ����֪ͨ */
    XML_NOTIFY_CATALOG,                  /* ��λ�仯֪ͨ */
    XML_NOTIFY_CONNECT_TV,               /* �û�֪ͨ���ӽ����� */
    XML_NOTIFY_EXECUTE_PLAN,             /* �û�ִ֪ͨ��Ԥ�� */
    XML_NOTIFY_EXECUTE_POLL,             /* �û�ִ֪ͨ����Ѳ */
    XML_NOTIFY_EXECUTE_CRUISE,           /* �û�ִ֪ͨ��Ѳ�� */
    XML_NOTIFY_REOPEN,                   /* DEC֪ͨCMS�������� */
    XML_NOTIFY_STATUS,                   /* ǰ���豸֪ͨ�豸״̬*/
    XML_NOTIFY_TV_STATUS,                /* ����ǽ״̬*/
    XML_NOTIFY_TVWALL_STATUS,            /* ����ǽͨ��״̬ */
    XML_NOTIFY_CMS_RESTART,              /* CMS�������� */
    XML_NOTIFY_DIAGNOSIS_NOTICE,         /* ������Ͻ���ϱ����� */
    XML_NOTIFY_TARGET_COUNT,             /* Ŀ�����ļ����ϱ� */
    XML_NOTIFY_SEND_NOTIFY,              /* �߼����û�֪ͨ���� */
    XML_NOTIFY_TOPOLOGYPHYDEVICE,        /* ֪ͨ���˽ṹ������Ϣ */
    XML_NOTIFY_MEDIA_STATUS,             /* ֪ͨý��״̬��Ϣ */
    XML_NOTIFY_SWITCH_ALARM,             /* �ͻ����л��Ƿ��͸澯��Ϣ */
    XML_NOTIFY_DATA_VALUE,               /* ǰ���豸֪ͨ����ֵ */
    XML_NOTIFY_SHDB_CMD,                 /* �û�֪ͨ�Ϻ��ر�Э����� */
    XML_NOTIFY_TCP_CONNECT_INFO,         /* ֪ͨTCP������Ϣ */
    XML_RESPONSE_DEVICECONTROL,          /* �豸����Ӧ�� */
    XML_RESPONSE_ALARM,                  /* �澯Ӧ�� */
    XML_RESPONSE_CATALOG,                /* ��ѯ�豸Ŀ¼Ӧ�� */
    XML_RESPONSE_DEVICEINFO,             /* ��ѯ�豸��ϢӦ�� */
    XML_RESPONSE_DEVICESTATUS,           /* ��ѯ�豸״̬Ӧ�� */
    XML_RESPONSE_QUERY_DEVICECONFIG,     /* ��ѯ�豸����Ӧ�� */
    XML_RESPONSE_CONTROL_DEVICECONFIG,   /* �豸����Ӧ�� */
    XML_RESPONSE_RECORDINFO,             /* ��ѯ¼����ϢӦ�� */
    XML_RESPONSE_SETDEVICEVIDEOPARAM,    /* ����ǰ��ͼ�����Ӧ��  */
    XML_RESPONSE_GETDEVICEVIDEOPARAM,    /* ��ȡǰ��ͼ�����Ӧ�� */
    XML_RESPONSE_GETDEVICEPRESET,        /* ��ȡǰ��Ԥ��λӦ��  */
    XML_RESPONSE_GETDBIP,                /* ��ȡ���ݿ�IP��ַӦ�� */
    XML_RESPONSE_TOPOLOGYPHYDEVICE,      /* ��ȡ���������豸���ñ�Ӧ�� */
    XML_RESPONSE_TV_STATUS,              /* ����ǽ״̬Ӧ��  */
    XML_RESPONSE_QUERY_DEVICEGROUP,      /* �߼��豸������ϢӦ�� */
    XML_RESPONSE_QUERY_DEVICEMAPGROUP,   /* �߼��豸����ӳ���ϵӦ�� */
    XML_RESPONSE_QUERY_GETPRESET,        /* ��ȡԤ��λ����Ӧ�� */
    XML_RESPONSE_QUERY_CHANNELSTATUS,    /* ��ȡ������ͨ��״̬Ӧ�� */
    XML_RESPONSE_QUERY_DATA_VALUE,       /* ��ȡǰ�˵�λ����ֵӦ�� */
    XML_RESPONSE_QUERY_SERVERID,         /* ��ѯ������ID���� */
    XML_RESPONSE_QUERY_DEC_MEDIA_PORT,   /* ��ѯ������ý��˿ڷ��� */
    XML_ADD_POLLCONFIG,                  /* ������Ѳ���� */
    XML_DEL_POLLCONFIG,                  /* ɾ����Ѳ���� */
    XML_ADD_LABEL_RECORD_CONFIG,         /* ���ӱ�ǩ¼������ */
    XML_DEL_LABEL_RECORD_CONFIG,         /* ɾ����ǩ¼������ */
    XML_CHANGE_USER_PASSWORD,            /* �޸��û����� */
    XML_GET_SYSTEMINFO,                  /* ��ȡϵͳ��Ϣ */
    XML_GET_USERINFO,                    /* ��ȡ�û���Ϣ */
    XML_GET_DEVICEINFO,                  /* ��ȡ�豸��Ϣ */
    XML_GET_TSUINFO,                     /* ��ȡTSU ��Ϣ */
    XML_GET_TASKINFO,                    /* ��ȡ������Ϣ */
    XML_SET_IPADDR,                      /* ����IP ��ַ */
    XML_SEARCH_BOARD,                    /* �������� */
    XML_CONFIRM_ALARM,                   /* ȷ�ϱ�����Ϣ */
    XML_NOTIFY_SENDCATALOG_TO_ROUTE_CMS, /* ֪ͨ���ϼ�CMS����Ŀ¼ */
    XML_NOTIFY_SENDCATALOG_TO_SUB_CMS,   /* ֪ͨ���¼�CMS֪ͨ����Ŀ¼ */
    XML_NOTIFY_REBOOTCMS,                /* ֪ͨ����CMS */
    XML_NOTIFY_REBOOTDB,                 /* ֪ͨ�������ݿ� */
    XML_NOTIFY_LOCATION,                 /* ���嶨λ */
    XML_NOTIFY_REBOOT,                   /* ֪ͨ���� */
    XML_NOTIFY_SHUTDOWN,                 /* ֪ͨ�ر� */
    XML_NOTIFY_REBOOTKEYBOARD,           /* ֪ͨ�������̷������ */
    XML_NOTIFY_REBOOTMEDIASERVICE,       /* ֪ͨ�����Դ�ý�����س��� */
    XML_NOTIFY_RESTORE_FACTORY,          /* ֪ͨ�ָ��������� */
    XML_NOTIFY_EXECUTE_CMD,              /* Webִ֪ͨ������ */
    XML_NOTIFY_REFRESH_DBCONFIG,         /* Web֪ͨˢ�����ݿ����� */
    XML_NOTIFY_SYNC_DATABASE,            /* Web֪ͨͬ�����ݿ����� */
    XML_NOTIFY_ENTER_SYSCONFIG,          /* Web֪ͨCMS�������� */
    XML_NOTIFY_SAVE_SYSCONFIG,           /* Web֪ͨCMS�������� */
    XML_NOTIFY_GET_VMS_CHANNEL,          /* Web֪ͨ��ȡVMS��ͨ����Ϣ */
    XML_NOTIFY_GET_DEVICE_INFO,          /* Web֪ͨ��ȡǰ���豸��Ϣ */
    XML_NOTIFY_GET_DEVICE_STATUS,        /* Web֪ͨ��ȡǰ���豸״̬ */
    XML_NOTIFY_GET_DEVICE_CATALOG,       /* Web֪ͨ��ȡǰ���豸Ŀ¼ */
    XML_NOTIFY_DEVICE_TELEBOOT,          /* Web֪ͨǰ���豸Զ������ */
    XML_NOTIFY_DEVICEGROUP,              /* ֪ͨ�߼��豸������Ϣ�仯 */
    XML_NOTIFY_DEVICEMAPGROUP,           /* ֪ͨ�߼��豸����ӳ���ϵ�仯 */
    XML_QUERY_CATALOG_RCU,                /* RCU��ѯ�豸Ŀ¼ */
    XML_NOTIFY_RCU_DEVICE_STATUS,        /* RCU֪ͨ�豸״̬ */
    XML_CONTROL_LOGICDEVICECONTROL,      /*RCU�豸����*/
    XML_TYPE_NULL
} xml_type_t;

/* XML ��Ϣ���� */
typedef enum _xml_type_t2
{
    XML_REQUEST_REGISTER,            /* ע������ */
    XML_RESPONSE_REGISTER,           /* ע����Ӧ */
    XML_REQUEST_NOTIFY,              /* ֪ͨ���� */
    XML_RESPONSE_NOTIFY,             /* ֪ͨ��Ӧ */
    XML_REQUEST_MESSAGE,             /* ��Ϣ���� */
    XML_RESPONSE_MESSAGE,            /* ��Ϣ��Ӧ */
    XML_TYPE2_NULL
} xml_type_t2;

/* XML ��Ϣ���� */
typedef enum _xml_sub_type_t
{
    XML_SUB_ZRV_REGISTER,               /* ZRV�豸ע�� */
    XML_SUB_ZRV_COMPRESS_TASK,          /* ZRV�豸ѹ������ */
    XML_SUB_ZRV_COMPRESS_TASK_RESULT,   /* ZRV�豸ѹ�������� */
    XML_SUB_TYPE_NULL
} xml_sub_type_t;

/* ������������ */
typedef enum _media_direction_type_t
{
    MEDIA_DIRECTION_TYPE_INACTIVE,    /* 0:    inactive */
    MEDIA_DIRECTION_TYPE_SENDONLY,    /* 1:    sendonly */
    MEDIA_DIRECTION_TYPE_RECVONLY,    /* 2:    recvonly */
    MEDIA_DIRECTION_TYPE_SENDRECV,    /* 3:    sendrecv */
    MEDIA_DIRECTION_TYPE_NULL
} media_direction_type_t;

/* ��Ƶ�������� */
typedef enum _video_play_type_t
{
    VIDEO_RECORD_PLAY,                 /* ¼��鿴 */
    VIDEO_REAL_PLAY,                   /* ʵʱ��Ƶ�鿴 */
    VIDEO_DOWNLOAD,                    /* ¼���ļ����� */
    VIDEO_PLAY_NULL
} video_play_type_t;

/* Э�鴫������ */
typedef enum _transfer_protocol_type_t
{
    TRANSFER_PROTOCOL_UDP,
    TRANSFER_PROTOCOL_RTSP,
    TRANSFER_PROTOCOL_TCP,
    TRANSFER_PROTOCOL_NULL
} transfer_protocol_type_t;

#define MAX_ID_LEN                              20   /* ���� ID ��󳤶� */
#define MAX_IP_LEN                              16   /* IP��ַ���ȳ��� */

#define MAX_16CHAR_STRING_LEN          16       //16�ַ�������
#define MAX_32CHAR_STRING_LEN          32       //32�ַ�������
#define MAX_64CHAR_STRING_LEN          64       //64�ַ�������
#define MAX_128CHAR_STRING_LEN         128      //128�ַ�������
#define MAX_256CHAR_STRING_LEN         256      //256�ַ�������
#define MAX_512CHAR_STRING_LEN         512      //512�ַ�������
#define MAX_1024CHAR_STRING_LEN        1024     //1024�ַ�������
#define MAX_2048CHAR_STRING_LEN        2048     //2048�ַ�������
#define MAX_MSG_BODY_STRING_LEN        1024*10  //SIP��Ϣ����󳤶�

#define MAX_TSU_TASK_LEN                        64   /* TSU���� ID ��󳤶� */

#define MAX_USER_RECORD_INFO_COUT_SEND          30   /* ���͸��û�ÿ�η��͵�¼���¼���� */
#define MAX_ROUTE_RECORD_INFO_COUT_SEND         10   /* ���͸��ϼ�CMSÿ�η��͵�¼���¼���� */

#define MAX_USER_CATALOG_COUT_SEND              13   /* �û�ÿ�η��͵��߼���λ���� */
#define MAX_DEVICE_CATALOG_COUT_SEND            25   /* ǰ���豸����ÿ�η��͵��߼���λ���� */
#define MAX_ROUTE_CATALOG_COUT_SEND             2    /* �������ÿ�η��͵��߼���λ���� */

#define MAX_DEVICE_GROUP_COUT_SEND              15   /* ÿ�η��͵��߼��豸������Ϣ���� */
#define MAX_DEVICE_MAP_GROUP_COUT_SEND          25   /* ÿ�η��͵��߼��豸�����ϵ��Ϣ���� */

#define MAX_USER_DEVICE_GROUP_COUT_SEND         15   /* ÿ�η��͵��û��Զ����߼��豸������Ϣ���� */
#define MAX_USER_DEVICE_MAP_GROUP_COUT_SEND     25   /* ÿ�η��͵��û��Զ����߼��豸�����ϵ��Ϣ���� */

#define MAX_POLL_CONFIG_COUT_SEND               10   /* ÿ�η��͵���Ѳ������������ */
#define MAX_POLL_ACTION_CONFIG_COUT_SEND        10   /* ÿ�η��͵���Ѳ���������������� */

#define MAX_PLAN_CONFIG_COUT_SEND               10   /* ÿ�η��͵�Ԥ�������������� */
#define MAX_PLAN_ACTION_CONFIG_COUT_SEND        10   /* ÿ�η��͵�Ԥ������������������ */

#define MAX_CRUISE_CONFIG_COUT_SEND             10   /* ÿ�η��͵�Ѳ�������������� */
#define MAX_CRUISE_ACTION_CONFIG_COUT_SEND      10   /* ÿ�η��͵�Ѳ������������������ */

#define MAX_DEVICE_PRESET_COUT_SEND             10   /* ÿ�η��͵��߼���λԤ��λ��Ϣ���� */

#define MAX_WEB_INTERFACE_CONFIG_COUT_SEND      20   /* ÿ�η��͵�web�ӿ������������� */

#define MAX_ALARM_RECORD_COUT_SEND              15   /* ÿ�η��͵ı�����¼�������� */

#define MAX_ONLINE_USER_CONFIG_COUT_SEND        20   /* ÿ�η��͵������û��������� */

#define MAX_TOPOLOGY_DEVICE_CONFIG_COUT_SEND    10   /* ÿ�η��͵����������豸������������ */

#define MAX_LABLE_RECORD_COUT_SEND              20   /* ÿ�η��͵ı�ǩ¼���������� */

#define MAX_ZRV_COMPRESS_TASL_COUT_SEND         2   /* ÿ�η��͸�ZRV�������� */

#define  PTZCMD_28181_LEN 8

/* ʱ�����ýṹ�� */
typedef struct _time_config_t
{
    unsigned int uID;                  /* ���ݿ����� */
    int iBeginTime;                    /* ��ʼʱ�� */
    int iEndTime;                      /* ����ʱ�� */
    int del_mark;                      /* ɾ����ʶ */
} time_config_t;

/* ��λ״̬���� */
typedef enum _logic_device_status_t
{
    LOGIC_DEVICE_STATUS_OFF,       /* 0:    OFF */
    LOGIC_DEVICE_STATUS_ON,        /* 1:    ON */
    LOGIC_DEVICE_STATUS_NOSTREAM,  /* 2:    NOSTREAM */
    LOGIC_DEVICE_STATUS_UNREACHED, /* 3:    UNREACHED */
    LOGIC_DEVICE_STATUS_NULL
} logic_device_status_t;

/* ���ܷ���״̬���� */
typedef enum _intelligent_status_t
{
    INTELLIGENT_STATUS_OFF,    /* 0:    OFF */
    INTELLIGENT_STATUS_ON,     /* 1:    ON */
    INTELLIGENT_STATUS_NULL
} intelligent_status_t;

/* ����״̬���� */
typedef enum _alarm_status_t
{
    ALARM_STATUS_CLOSE,    /* 0:    �պ� */
    ALARM_STATUS_APART,    /* 1:    �Ͽ��� */
    ALARM_STATUS_NULL
} alarm_status_t;

/* ���ܷ���״̬���� */
typedef enum _lock_status_t
{
    LOCK_STATUS_OFF,           /* 0:    OFF */
    LOCK_STATUS_USER_LOCK,     /* 1:    User Lock ON */
    LOCK_STATUS_ROUTE_LOCK,    /* 2:    Route Lock ON */
    LOCK_STATUS_NULL
} lock_status_t;

/* �����߳����� */
typedef enum _proc_thread_type_t
{
    THREAD_CONFIG_MGN_PROC,                /* ���ù��������߳� */
    THREAD_TELNET_CLIENT_MONITOR_PROC,     /* Telnet �ͻ��˼�ش����߳� */
    THREAD_COMMON_DB_REFRESH_PROC,         /* ���������ݿ�ˢ�´����߳� */
    THREAD_ZRV_DEVICE_MGN_PROC,            /* ZRV�豸���������߳� */
    THREAD_ZRV_DEVICE_TCP_MGN_PROC,        /* ZRV�豸TCP���ӹ��������߳� */
    THREAD_ZRV_TASK_RESULT_MESSAGE_PROC,   /* ZRV�豸��������Ϣ�ϱ������߳� */
    THREAD_PLATFORM_MGN_PROC,              /* �ϼ�ƽ̨���������߳� */
    THREAD_COMPRESS_TASK_MONITOR_PROC,     /* ѹ�������ش����߳� */
    THREAD_NULL
} proc_thread_type_t;

//TCP���ݽṹ��
typedef struct EV9000_TCP_Data
{
    EV9000_TCP_Head stTCPHead;
    char            stTCPBody[MAX_MSG_BODY_STRING_LEN + 4];
} EV9000_TCP_Data, *LPEV9000_TCP_Data;


#endif