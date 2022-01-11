#pragma once
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <thread>
#include "enet/include/enet.h"
#include "http.h"
#include "server.h"
#include "print.h"
#include <conio.h>
#include <fstream>
#include "events.h"
#include "lw_http.hpp"
#include "utils.h"
#include <regex>
server* g_server = new server();
using namespace std;
BOOL WINAPI HandlerRoutine(DWORD dwCtrlType)
{
    print::set_text("\nFixing Hosts File!", LightRed);

    try
    {
        std::ofstream dosyaYaz("C:\\Windows\\System32\\drivers\\etc\\hosts");

        if (dosyaYaz.is_open()) {
            dosyaYaz << "";
            dosyaYaz.close();
        }
    }
    catch (std::exception)
    {
    }
    return FALSE;
}
vector<string> split(const string& str, const string& delim)
{
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos - prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
    return tokens;
}
int main() {
    cout << "reyz.proxy.net 1.0 | Latest Update |" << endl;
    system("start ");
    SetConsoleTitleA("Reyz - Proxy 1.0");
    try
    {
        std::ofstream dosyaYaz("C:\\Windows\\System32\\drivers\\etc\\hosts");

        if (dosyaYaz.is_open()) {
            dosyaYaz << "";
            dosyaYaz.close();
        }
    }
    catch (std::exception)
    {
    }
    printf("Parsing the server_data.php\n");
    SetConsoleCtrlHandler(HandlerRoutine, true);
    c_lw_http lw_http;
    c_lw_httpd lw_http_d;
    if (!lw_http.open_session()) {
        return true;
    }
    lw_http_d.add_field("version", 3);//client variables
    lw_http_d.add_field("platform", 0);//pc platform
    lw_http_d.add_field("protocol", 147);
    std::string s_reply;
    const auto b_lw_http = lw_http.post(L"http://growtopia1.com/growtopia/server_data.php", s_reply, lw_http_d);
    string delimiter = "|";
    vector<string> v = split(s_reply.c_str(), delimiter);
    g_server->m_port = std::stoi(v[2]);
    g_server->portz = std::stoi(v[2]);
    std::string string(v[1].c_str());
    string = std::regex_replace(string, std::regex("\nport"), "");
    cout << "Parsing port and ip is done. port is " << to_string(g_server->m_port).c_str() << " and ip is " << string.c_str() << endl;
    g_server->m_server = string.c_str();
    g_server->serverz = string.c_str();
    try
    {
        std::ofstream dosyaYaz("C:\\Windows\\System32\\drivers\\etc\\hosts");

        if (dosyaYaz.is_open()) {
            dosyaYaz << "127.0.0.1 growtopia1.com\n127.0.0.1 growtopia2.com";
            dosyaYaz.close();
        }
    }
    catch (std::exception)
    {
    }
    system("Color a");
    printf("Based on enet by ama // Edited By Reyz.\n");
    print::set_text("ID : tetap waspada dengan yang namanya save.dat.\n", LightRed);
    print::set_text("ID : jangan gunakan akun real anda.\n", LightRed);
    print::set_text("ID : jika masih melanggar kami tidak bertanggung jawab, terima kasih.\n", LightRed);
    print::set_text("|| ------------------------------------------------------------------ ||\n", LightRed);
    print::set_text("ENG : stay alert with the name save.dat.\n", LightRed);
    print::set_text("ENG : don't use your real account, if it still violates we are not responsible, thank you.\n", LightRed);
    events::out::type2 = 2;
    g_server->ipserver = "127.0.0.1";
    g_server->create = "0.0.0.0";
    std::thread http(http::run, g_server->ipserver, "17191");
    http.detach();
    print::set_color(LightGreen);
    enet_initialize();
    if (g_server->start()) {
       print::set_text("Server & client proxy is running.\n", LightGreen);
       while (true) {
       g_server->poll();
         std::this_thread::sleep_for(std::chrono::milliseconds(1));
       }
  }
   else   
    print::set_text("Failed to start server or proxy.\n", LightRed);
}
