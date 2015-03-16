#ifndef _MAPLOADER_H
#define _MAPLOADER_H

#include <windows.h>
#include <iostream>
#include <string>
#include <exception>
#include <tinyxml.h>

#include "Map.h"
#include "BackgroundElement.h"

/*	Doc
 *		Version minimaliste du chargement de Map
 *		Utilisation du format XML et de la lib tinyXML ATM
 */

/*	TODO:
 *		- Chercher tout le contenu de Map
 *		- Sécuriser le format
 */

namespace GameLogic
{
	class MapLoader
	{
	public:
		static Map loadMap(std::string path);

	private:
		static BackgroundElement* parseBackgroundElement(TiXmlElement *childElement);
		//DEBUG
		static std::string ExePath();
	};
}

#endif