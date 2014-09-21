/**
 * Personal: 
 *
 * File Name: init.el
 * Created Time: 2014/8/18
 * Edited By: ShiNing
 *
 * Copyright (c) 2014 ShiNing, Colibri Team, All Rights Reserved.
 *
 * |-------+---------+-----------+----------+------|
 * |  版本 | 作者    | 时间      | 修订说明 | 备注 |
 * |-------+---------+-----------+----------+------|
 * | 0.0.1 | ShiNing | 2014/8/18 | 创建文件 |      |
 * |-------+---------+-----------+----------+------|
 *
 * License:
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Emacs; see the file COPYING.  If not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 * Desctiption:
 * 
 * Code example for parsing a XML file.
 *
 * end! */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

void parseStory(xmlDocPtr doc, xmlNodePtr cur)
{
  xmlChar *key;
  
  cur = cur->xmlChildrenNode;
  while (NULL != cur) {
    if ((!xmlStrcmp(cur->name, (const xmlChar *)"keyword"))) {
      key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
      printf("keyword: %s\n", key);
      xmlFree(key);
    }
    
    cur = cur->next;
  }

  return ;
}

static void parseDoc(char *docname)
{
  xmlDocPtr doc = NULL;
  xmlNodePtr cur = NULL;

  // parse the xml document
  doc = xmlParseFile(docname);
  if (NULL == doc) {
    fprintf(stderr, "Document not parsed successful.\n");
    return ;
  }

  // get the root element
  cur = xmlDocGetRootElement(doc);
  if (NULL == cur) {
    fprintf(stderr, "empty document.\n");
    xmlFreeDoc(doc);
    return ;
  }

  if (xmlStrcmp(cur->name, (const xmlChar *)"story")) {
    fprintf(stderr, "document of the wrong type, root node != story.\n");
    xmlFreeDoc(doc);
  }

  cur = cur->xmlChildrenNode;
  while (NULL != cur) {
    if ((!xmlStrcmp(cur->name, (const xmlChar *)"storyinfo"))) {
      parseStory (doc, cur);
    }

    cur = cur->next;
  }

  xmlFreeDoc (doc);
  return ;
}

int main(int argc, const char *argv[])
{
  char *docname = NULL;

  if (argc <= 1) {
    printf("Usgae: parser docname.\n");
    return 1;
  }

  docname = argv[1];
  parseDoc(docname);
  
  return 0;
}
