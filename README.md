# mbr_info
显示磁盘镜像文件的MBR分区表信息

功能：解析mbr 分区表信息；

实现：借鉴grub2中定义的相关结构；

目标：分析启动代码，分析grub2引导过程；

get_bootloader_code.sh:获取引导区的汇编代码：
	get_bootloader_code.sh /dev/sda mbr.s
	get_bootloader_code.sh sda.img mbr.s
mbr_info:格式化显示mbr信息
	./mbr_info /dev/sda
	./mbr_info sda.img
mbr_info.c:格式化输出源代码
mbr.s：获取到的引导汇编代码
README.md：本文件
sda.img：范例磁盘镜像
