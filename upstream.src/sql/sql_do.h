/* Copyright (c) 2006, 2022, Oracle and/or its affiliates.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License, version 2.0,
   as published by the Free Software Foundation.

   This program is also distributed with certain software (including
   but not limited to OpenSSL) that is licensed under separate terms,
   as designated in a particular file or component or in included license
   documentation.  The authors of MySQL hereby grant you an additional
   permission to link the program and your derivative works with the
   separately licensed software that they have included with MySQL.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License, version 2.0, for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA */

#ifndef SQL_DO_INCLUDED
#define SQL_DO_INCLUDED

#include "sql_class.h"
 
class THD;
struct LEX;

class Query_result_do :public Query_result
{
public:
  Query_result_do(THD *thd): Query_result() {}
  bool send_result_set_metadata(List<Item> &list, uint flags) { return false; }
  bool send_data(List<Item> &items);
  bool send_eof();
  virtual bool check_simple_select() const { return false; }
  void abort_result_set() {}
  virtual void cleanup() {}
};

bool mysql_do(THD *thd, LEX *lex);

#endif /* SQL_DO_INCLUDED */
