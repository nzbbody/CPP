#include "media_dispatch_i.h"
#include "media_node_i.h"
#include "media_parser_i.h"
#include "media_socket_i.h"
#include "media_packet_i.h"


#define MEDIA_THREAD_MAX	4


t_int32 streamTransInit();

t_int32 streamTransExit();