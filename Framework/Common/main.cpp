#include <iostream>
#include "IApplication.hpp"
using namespace std;
using namespace My;

namespace My{
	extern IApplication* g_pApp;
}	

int main(int argc, char** argv)
{
	int ret;

	if((ret = g_pApp->Initialize())!=0){
		cout << "App Initialize failed, will exit now." << endl;
		return ret;
	}

	while (!g_pApp->IsQuit()){
		g_pApp->Tick();
	}

	g_pApp->Finalize();
	
	return 0;
}

