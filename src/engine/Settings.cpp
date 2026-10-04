#include "engine/core/Settings.hpp"
#include <iostream>
#include <string>
#include "tinyxml2.h"

std::string AssetPath = "Assets";
string SpritePath = AssetPath + "/Sprites";

using namespace tinyxml2;

int GetIntXML(XMLElement* from, const char* key) {
    int _value;
    XMLElement* element = from->FirstChildElement(key);
    if (element)
    {
        element->QueryIntText(&_value);
    }
    return _value;
}
int GetBoolXML(XMLElement* from, const char* key) {
    bool _value;
    XMLElement* element = from->FirstChildElement(key);
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
    XMLError result = doc.LoadFile("Assets/config.xml");
    if (result != XML_SUCCESS)
    {
        throw std::runtime_error("Error: Couldn't load Config file (should be located at 'Assets/config.xml')");
    }

    // Getting <config> header
    XMLElement* conf = doc.FirstChildElement("config");
    if (conf == nullptr) {
        throw std::runtime_error("There's no <config> header");
    }

    // Setting Screen Width and Height
    c.WIDTH = GetIntXML(conf, "width");    
    c.HEIGHT = GetIntXML(conf, "height");
    // Setting MaxFPS
    c.maxFPS = GetIntXML(conf, "maxFPS");
    // Setting Fullscreen
    c.Fullscreen = GetBoolXML(conf, "fullscreen");

    return c;
}

XMLElement* SetValue(XMLDocument& doc, char* key) {
    XMLElement* elem = doc.FirstChildElement(key);
    if (elem == nullptr) {
        elem = doc.NewElement(key);
        doc.InsertFirstChild(elem);
    }

    return elem;
}

XMLElement* SetValue(XMLDocument& doc, XMLElement* elmnt, char* key) {
    XMLElement* elem = elmnt->FirstChildElement(key);
    if (elem == nullptr) {
        elem = doc.NewElement(key);
        elmnt->InsertEndChild(elem);
    }

    return elem;
}

bool Save(Configs c) {
    XMLDocument doc;

    // Loading File
    XMLError result = doc.LoadFile("Assets/config.xml");
    if (result != XML_SUCCESS)
    {
        throw std::runtime_error("Error: Couldn't load Config file (should be located at 'Assets/config.xml')");
    }

    // Setting <config> header
    XMLElement* conf = SetValue(doc, "config");
    // Setting Screen Width and Height
    XMLElement* width = SetValue(doc, conf, "width");
    width->SetText(c.WIDTH);
    XMLElement* height = SetValue(doc, conf, "height");
    height->SetText(c.HEIGHT);
    // Setting MaxFPS
    XMLElement* m_FPS = SetValue(doc, conf, "maxFPS");
    m_FPS->SetText(c.maxFPS);
    //Setting Fullscreen value
    XMLElement* fullscreen = SetValue(doc, conf, "fullscreen");
    fullscreen->SetText(c.Fullscreen ? 1 : 0);

    return doc.SaveFile("Assets/config.xml") == XML_SUCCESS;
}