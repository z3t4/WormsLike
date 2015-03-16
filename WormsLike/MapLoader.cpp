#include "MapLoader.h"

namespace GameLogic
{
	Map MapLoader::loadMap(std::string path)
	{
		std::string backgroundPath;
		std::vector<BackgroundElement*> backgroundElements;
		TiXmlDocument doc(path.c_str());
		if (!doc.LoadFile()){
			std::cerr << "erreur lors du chargement" << std::endl;
			std::cerr << "error #" << doc.ErrorId() << " : " << doc.ErrorDesc() << std::endl;
			std::cerr << ExePath() << std::endl;
			throw std::exception("LoadError");
		}

		TiXmlElement *mapElement = doc.FirstChildElement();
		std::string name = mapElement->Attribute("name");

		//DEBUG
		std::cerr << name << std::endl;

		TiXmlElement *childElement = mapElement->FirstChildElement();
		while (childElement)
		{
			std::string childName = childElement->Value();
			if (childName == "Background")
			{
				backgroundPath = childElement->Attribute("src");
			}
			else if (childName == "Element")
			{
				backgroundElements.push_back(parseBackgroundElement(childElement));
			}
			else
			{
				std::cerr << "Nom de noeud Incorrect : " << childName << std::endl;
				throw std::exception("IncorrectNodeName");
			}
			childElement = childElement->NextSiblingElement();
		}
		return Map(name, backgroundPath, backgroundElements);
	}

	BackgroundElement* MapLoader::parseBackgroundElement(TiXmlElement *childElement)
	{
		std::string elementType = childElement->Attribute("type");
		BackgroundElement::Type type;
		if (elementType == "grab")
		{
			type = BackgroundElement::Type::Grabbable;
		}
		else if (elementType == "ungrab")
		{
			type = BackgroundElement::Type::UnGrabbable;
		}
		else if (elementType == "ennemy")
		{
			type = BackgroundElement::Type::Ennemy;
		}
		else if (elementType == "backg")
		{
			type = BackgroundElement::Type::Background;
		}
		else
		{
			std::cerr << "Type de Element Incorrect : " << elementType << std::endl;
			throw std::exception("IncorrectNodeName");
		}
		return new BackgroundElement(
			type, // Type
			std::atoi(childElement->Attribute("x")), // x 
			std::atoi(childElement->Attribute("y")), // y
			std::atoi(childElement->Attribute("sizeX")), // sizeX
			std::atoi(childElement->Attribute("sizeY")), //sizeY
			childElement->Attribute("src")); //imagePath
		
	}

	std::string MapLoader::ExePath()
	{
		char buffer[MAX_PATH];
		GetModuleFileName(NULL, buffer, MAX_PATH);
		std::string::size_type pos = std::string(buffer).find_last_of("\\/");
		return std::string(buffer).substr(0, pos);
	}
} 