#ifndef _WINDOW_H
#define _WINDOW_H

namespace Engine 
{
	class Window
	{
	public:
		Window();
		int start();
	private:
		int init();
		int close();
	};
}

#endif