INCLUDEPATH += C:/Projects/OpenCV/opencv/build/install/include

VERSION_BUILD = 343

#win32-g++{
#LIBS +=-L"D:/opencv/build/install/x86/mingw/lib"
#LIBS +=  \
#        -lopencv_core$${VERSION_BUILD} \
#        -lopencv_highgui$${VERSION_BUILD} \
#        -lopencv_imgcodecs$${VERSION_BUILD} \
#        -lopencv_imgproc$${VERSION_BUILD} \
#        -lopencv_video$${VERSION_BUILD} \
#        -lopencv_videoio$${VERSION_BUILD} \
#        -lopencv_videostab$${VERSION_BUILD} \
#}

win32-msvc*{
    LIBS += -LC:/Projects/OpenCV/opencv/build/install/x64/vc15/lib
    CONFIG(debug,debug|release) {
        LIBS += -lopencv_core$${VERSION_BUILD}d
        LIBS += -lopencv_imgproc$${VERSION_BUILD}d
        LIBS += -lopencv_highgui$${VERSION_BUILD}d
        LIBS += -lopencv_features2d$${VERSION_BUILD}d
        LIBS += -lopencv_videoio$${VERSION_BUILD}d
        LIBS += -lopencv_video$${VERSION_BUILD}d
        LIBS += -lopencv_objdetect$${VERSION_BUILD}d
        LIBS += -lopencv_imgcodecs$${VERSION_BUILD}d
        LIBS += -lopencv_calib3d$${VERSION_BUILD}d
        LIBS += -lopencv_xfeatures2d$${VERSION_BUILD}d
        LIBS += -lopencv_videostab$${VERSION_BUILD}d
        LIBS += -lopencv_tracking$${VERSION_BUILD}d
    }
    CONFIG(release,debug|release) {
        LIBS += -lopencv_core$${VERSION_BUILD}
        LIBS += -lopencv_imgproc$${VERSION_BUILD}
        LIBS += -lopencv_highgui$${VERSION_BUILD}
        LIBS += -lopencv_features2d$${VERSION_BUILD}
        LIBS += -lopencv_videoio$${VERSION_BUILD}
        LIBS += -lopencv_video$${VERSION_BUILD}
        LIBS += -lopencv_objdetect$${VERSION_BUILD}
        LIBS += -lopencv_imgcodecs$${VERSION_BUILD}
        LIBS += -lopencv_calib3d$${VERSION_BUILD}
        LIBS += -lopencv_xfeatures2d$${VERSION_BUILD}
        LIBS += -lopencv_videostab$${VERSION_BUILD}
        LIBS += -lopencv_tracking$${VERSION_BUILD}
    }
}

unix {
        LIBS += -lopencv_core
        LIBS += -lopencv_imgproc
        LIBS += -lopencv_highgui
        LIBS += -lopencv_features2d
        LIBS += -lopencv_videoio
        LIBS += -lopencv_video
        LIBS += -lopencv_objdetect
        LIBS += -lopencv_imgcodecs
        LIBS += -lopencv_calib3d
        LIBS += -lopencv_xfeatures2d
        LIBS += -lopencv_videostab
        LIBS += -lopencv_tracking
}
