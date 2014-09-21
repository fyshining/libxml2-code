### Personal: 
##  
## File Name: init.el
## Created Time: 2014/8/18
## Edited By: ShiNing
##
## Copyright (c) 2014 ShiNing, Colibri Team, All Rights Reserved.
##
## |-------+---------+-----------+----------+------|
## |  版本 | 作者    | 时间      | 修订说明 | 备注 |
## |-------+---------+-----------+----------+------|
## | 0.0.1 | ShiNing | 2014/8/18 | 创建文件 |      |
## |-------+---------+-----------+----------+------|
##
### License:
##
## This program is free software; you can redistribute it and/or
## modify it under the terms of the GNU General Public License
## as published by the Free Software Foundation; either version 3
## of the License, or (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with GNU Emacs; see the file COPYING.  If not, write to the
## Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
## Boston, MA 02110-1301, USA.
##
### end!

CFLAGS=`xml2-config --cflags`
CLIBS=`xml2-config --libs`

all: parse-file

parse-file:
	gcc -o parse-file $(CFLAGS) parse-file.c $(CLIBS)

clean:
	rm -rf *~
	rm -f parse-file
