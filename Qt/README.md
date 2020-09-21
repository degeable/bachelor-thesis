Qt Prototypes
===============

This folder contains some Qt Projects.

The Templates folder contains two baisc projects that are using two different approaches to render openGL as own QML item.
These are the two best ways to do the openGl rendereing as far as i learned in the last few days. Maybe there will be a better solution but i will stick to the FrameBufferObject because it looked the best and easiest to me. For more on that take a look [here](https://www.qt.io/blog/2015/05/11/integrating-custom-opengl-rendering-with-qt-quick-via-qquickframebufferobject) 

1.QQuickItem
----------

The project **QQuickItem** is a straight copy of [THIS](https://doc.qt.io/qt-5/qtquick-scenegraph-openglunderqml-example.html) example but with the OpenGl replaced by a simple coloured triangle. 
In theory, you can paste your openGL code into the paint() and init() function of vha.cpp and it should be rendered like any other QQuickItem.
The idea is that the "vha" class derivates from QQuickItem and has an own renderer class. In the `main.cpp` this new class will be registered and can be used in the qml file.

2.FrameBufferObject
-----------------

The project **FrameBufferObject** is using a different approach but it can be used in QML the same way as the QQuckItem.
The class derivates from **QQuickFramebufferObject** and also has its own Renderer class that derivates from **QQuickFramebufferObject::Renderer**.
It uses a FrambufferObject for the rendering and it is registered in the `main.cpp` like in the QQuckItem project. 
The same coloured triangle as in the **QQuickItem** project is used here.


VisualHearingAid
--------------------

In this folder you can find the VHA Qt project with the different inherented watch classes from the original project. It uses the FrameBufferObject approach as you can find in `Attempts/new_openGL_Code/VHA_FrameBufferObject`.
This will be the main Project that I will be working on.
This Project wil also feature the Watch classes.

In the `tools` folder you can find a compass.py. This will send the compass data of the Matrix creator via socket to the App. Right now ip is hardcoded at line **63**. To run this you need to have the `hardware abstraction layer` package installed. Try this ```pip install python-matrixio-hal```.

Note: In line 129 of the VisualHearingAid.cpp file, there is a smoothing function because the Matrix Creator sends shaky compass data. But this will cause minor delay...
