/*
 * synergy -- mouse and keyboard sharing utility
 * Copyright (C) 2014 Bolton Software Ltd.
 * 
 * This package is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * found in the file COPYING that should have accompanied this file.
 * 
 * This package is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "base/String.h"

#include <stdio.h>
#include <cstdarg>

void
find_replace_all(
	CString& subject,
	const CString& find,
	const CString& replace)
{
	size_t pos = 0;
	while ((pos = subject.find(find, pos)) != CString::npos) {
		 subject.replace(pos, find.length(), replace);
		 pos += replace.length();
	}
}

CString
string_format(const std::string fmt, ...)
{
	int size = 100;
	std::string str;
	va_list ap;

	while (true) {
		str.resize(size);
		va_start(ap, fmt);
		int n = vsnprintf((char *)str.c_str(), size, fmt.c_str(), ap);
		va_end(ap);

		if (n > -1 && n < size) {
			str.resize(n);
			return str;
		}
		if (n > -1) {
			size = n + 1;
		}
		else {
			size *= 2;
		}
	}

	return str;
}