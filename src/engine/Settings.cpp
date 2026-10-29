#include "engine/core/Settings.hpp"
#include "engine/core/Utils.hpp"
#include <iostream>
#include <string>
#include "tinyxml2.h"

std::string AssetPath = "assets";
std::string SpritePath = AssetPath + "/Sprites";
std::string configPath = AssetPath+"/config.xml";

using namespace tinyxml2;

int GetIntXML(XMLElement* from, std::string key) {
    int _value = 0;
    XMLElement* element = from->FirstChildElement(key.c_str());
    if (!element)
        return _value;
    if (element->QueryIntText(&_value) != XML_SUCCESS)
        return 0;
    return _value;
}
int GetIntXML(XMLElement* from, std::string key, int default_value) {
    int _value = default_value;
    XMLElement* element = from->FirstChildElement(key.c_str());
    if (!element)
        return _value;
    if (element->QueryIntText(&_value) != XML_SUCCESS)
        return default_value;
    return _value;
}
bool GetBoolXML(XMLElement* from, std::string key, bool default_value = false) {
    bool _value = default_value;
    XMLElement* element = from->FirstChildElement(key.c_str());
    if (element && element->GetText()) {
        std::string value = element->GetText();

        _value =
            value == "true" ||
            value == "1" ||
            value == "yes";
    }
    return _value;
}

Configs Load() {
    Configs c;
    XMLDocument doc;

    // Loading File
   
    XMLError result = doc.LoadFile(configPath.c_str());
    if (result != XML_SUCCESS)
    {
        if (result == XML_ERROR_FILE_NOT_FOUND)
        {
            Save();
        }
        
        throw std::runtime_error("Error: Couldn't load Config file (should be located at 'Assets/config.xml')");
    }

    // Getting <config> header
    XMLElement* conf = doc.FirstChildElement("config");
    if (conf == nullptr) {
        throw std::runtime_error("There's no <config> header");
    }

    // Setting Screen Width and Height
    c.WIDTH = GetIntXML(conf, "width", 1280);    
    c.HEIGHT = GetIntXML(conf, "height", 720);
    // Setting MaxFPS
    c.maxFPS = GetIntXML(conf, "maxFPS", 60);
    // Setting Fullscreen
    c.Fullscreen = GetBoolXML(conf, "fullscreen");

    return c;
}

XMLElement* SetValue(XMLDocument& doc, std::string key) {
    XMLElement* elem = doc.FirstChildElement(key.c_str());
    if (elem == nullptr) {
        elem = doc.NewElement(key.c_str());
        doc.InsertFirstChild(elem);
    }

    return elem;
}

void SetValue(XMLDocument& doc, XMLElement* elmnt, std::string key, auto value) {
    XMLElement* elem = elmnt->FirstChildElement(key.c_str());
    if (elem == nullptr) {
        elem = doc.NewElement(key.c_str());
        elmnt->InsertEndChild(elem);
    }
    
    elem->SetText(std::to_string(value).c_str());
}

void Save() {
    XMLDocument doc;

    // Setting <config> header
    XMLElement* conf = SetValue(doc, "config");
    // Setting Screen Width and Height
    SetValue(doc, conf, "width", 1280);
    SetValue(doc, conf, "height", 720);
    // Setting MaxFPS
    SetValue(doc, conf, "maxFPS", 60);
    //Setting Fullscreen value
    SetValue(doc, conf, "fullscreen", false);

    if (doc.SaveFile(configPath.c_str()) == XML_SUCCESS)
    {
        Error("Choose a god and start praying, error when saving default save file: ", doc.ErrorStr());
    }
}

bool Save(Configs c) {
    XMLDocument doc;

    // Loading File
    XMLError result = doc.LoadFile(configPath.c_str());
    if (result != XML_SUCCESS)
    {
        throw std::runtime_error("Error: Couldn't save Config file (should be located at 'Assets/config.xml')");
    }

    // Setting <config> header
    XMLElement* conf = SetValue(doc, "config");
    // Setting Screen Width and Height
    SetValue(doc, conf, "width", c.WIDTH);
    SetValue(doc, conf, "height", c.HEIGHT);
    // Setting MaxFPS
    SetValue(doc, conf, "maxFPS", c.maxFPS);
    //Setting Fullscreen value
    SetValue(doc, conf, "fullscreen", c.Fullscreen ? 1 : 0);

    return doc.SaveFile(configPath.c_str()) == XML_SUCCESS;
}