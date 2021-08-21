#pragma once
#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>
#include <fstream>

#pragma comment (lib, "Ws2_32.lib")
using namespace std;

SOCKET connect_host(string ip, string port);
int local(SOCKET sock, string lpath, string rpath);
int remote(SOCKET sock, string lpath, string rpath);
