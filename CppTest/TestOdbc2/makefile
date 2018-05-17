# Copyright (c) 2013, 浙江大华系统工程公司
# All rights reserved.
# 摘　　要：makefile例子
# 当前版本：1.0
# 原作者　：汪德奇
# 完成日期：2013年07月18日
# 修订记录：创建

#需要包含makeconfig,makeconfig里定义了基本的配置项,如CXX LD等
include $(APP_HOME)/makeconfig

#编译程序main
BINTARGET=TestOdbc

#定义main使用的目标文件(.o)
SOURCES = $(wildcard *.cpp)
BINOBJS = $(patsubst %.cpp, %.o, $(SOURCES))

#头文件搜索路径
INCLUDEPATH += \
	$(APP_HOME)/include	

#定义编译参数
CXXFLAGS += \
	-DOTL_ODBC -DOTL_ODBC_UNIX -ldl

#定义引用的库文件路径
LIBPATH += \

#定义链接时引用的ibp库文件
IBPLIBS += 	\

#定义链接时引用的系统库文件和第三方库文件
SYSLIBS += \
	odbc

#链接执行程序,链接这个项目编译出来的库
$(BINTARGET) : $(BINOBJS)
	$(LD) $(LDFLAGS) -o $@ $(BINOBJS)

$(BINOBJS): %.o:%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

#清理
clean:
	$(RM) $(BINTARGET) $(BINOBJS)
	
#清理obj
clean_target:
	$(RM) $(BINTARGET)