/*
 * Copyright (c) 2009-2016, Albertas Vyšniauskas
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 *     * Neither the name of the software author nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "StringUtils.h"
using namespace std;

void split(const std::string &str, char separator, bool skip_empty, std::function<void(const std::string &)> function)
{
	size_t start = 0;
	size_t separator_position = str.find(separator);
	if (separator_position == string::npos){
		if (skip_empty && str.empty()) return;
		function(str);
		return;
	}
	do{
		if (!skip_empty || separator_position - start > 0)
			function(str.substr(start, separator_position - start));
		start = separator_position + 1;
		separator_position = str.find(separator, start);
	}while (separator_position != string::npos);
	if (start != str.length()){
		function(str.substr(start, str.length() - start));
	}else if (!skip_empty){
		function(string());
	}
}
void stripLeadingTrailingChars(std::string &str, const std::string &strip_chars)
{
	if (str.empty()) return;
	if (strip_chars.empty()) return;
	size_t start = str.find_first_not_of(strip_chars);
	size_t end = str.find_last_not_of(strip_chars);
	if ((start == string::npos) || (end == string::npos)){
		str.erase();
		return;
	}
	str = str.substr(start, end - start + 1);
}
