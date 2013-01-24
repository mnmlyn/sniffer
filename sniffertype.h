// =====================================================================================
// 
//       Filename:  sniffertype.h
//
//    Description:  一些关键结构和常量的定义头文件
//
//        Version:  1.0
//        Created:  2013年01月23日 20时39分49秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#ifndef SNIFFERTYPE_H_
#define SNIFFERTYPE_H_

#define UDP_SIGN		17		// UDP协议标识
#define QQ_SIGN			'\x02'	// OICQ协议标识
#define QQ_SER_PORT		8000	// QQ服务器所用端口号
#define QQ_NUM_OFFSET	7		// QQ号码信息在QQ协议头中的偏移

// Mac头部（14字节） 
typedef struct eth_header  
{  
	unsigned char dstmac[6];	// 目标mac地址  
	unsigned char srcmac[6];	// 源mac地址  
	unsigned short eth_type;	// 以太网类型  
}eth_header;  


// IP地址（4字节）
typedef struct ip_address
{
	unsigned char byte1;
	unsigned char byte2;
	unsigned char byte3;
	unsigned char byte4;
}ip_address;

// IPv4头部（20字节）
typedef struct ip_header
{
	unsigned char		ver_ihl;        // 版本 (4 bits) + 首部长度 (4 bits)
	unsigned char		tos;            // 服务类型(Type of service) 
	unsigned short		tlen;           // 总长(Total length) 
	unsigned short		identification; // 标识(Identification)
	unsigned short		flags_fo;       // 标志位(Flags) (3 bits) + 段偏移量(Fragment offset) (13 bits)
	unsigned char		ttl;            // 存活时间(Time to live)
	unsigned char		proto;          // 协议(Protocol)
	unsigned short		crc;			// 首部校验和(Header checksum)
	ip_address			saddr;			// 源地址(Source address)
	ip_address			daddr;			// 目的地址(Destination address)
	unsigned int		op_pad;         // 选项与填充(Option + Padding)
}ip_header;

// TCP头部（20字节）
typedef struct tcp_header
{
	unsigned short	src_port;			// 源端口号
	unsigned short	dst_port;			// 目的端口号
	unsigned int	seq_no;				// 序列号
	unsigned int	ack_no;				// 确认号
	unsigned char	thl:4;				// tcp头部长度
	unsigned char	reserved_1:4;		// 保留6位中的4位首部长度
	unsigned char	reseverd_2:2;		// 保留6位中的2位
	unsigned char	flag:6;				// 6位标志 
	unsigned short	wnd_size;			// 16位窗口大小
	unsigned short	chk_sum;			// 16位TCP检验和
	unsigned short	urgt_p;				// 16为紧急指针
}tcp_header;

// UDP头部（8字节）
typedef struct udp_header
{
	unsigned short	sport;		// 源端口(Source port)
	unsigned short	dport;		// 目的端口(Destination port)
	unsigned short	len;		// UDP数据包长度(Datagram length)
	unsigned short	crc;		// 校验和(Checksum)
}udp_header;

// ICMP头部（4字节）
typedef struct icmp_header
{
	unsigned char	icmp_type;	// 类型
	unsigned char	code;		// 代码
	unsigned short	chk_sum;	// 16位检验和
}icmp_header;

#endif	// SNIFFERTYPE_H_