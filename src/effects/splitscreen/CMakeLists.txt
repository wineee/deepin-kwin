#######################################
# Effect

set(splitscreen_SOURCES
    main.cpp
    splitprevieweffect.cpp
)

find_package(Qt${QT_VERSION_MAJOR} CONFIG REQUIRED COMPONENTS
    QuickWidgets
)

kwin4_add_effect_module(kwin4_effect_splitscreen ${splitscreen_SOURCES})
target_link_libraries(kwin4_effect_splitscreen PRIVATE
    kwineffects
    Qt${QT_VERSION_MAJOR}::QuickWidgets
    Qt${QT_VERSION_MAJOR}::DBus
    #Qt${QT_VERSION_MAJOR}::X11Extras
    KF6::ConfigGui
)

install(DIRECTORY qml DESTINATION ${KDE_INSTALL_DATADIR}/kwin/effects/splitscreen)

