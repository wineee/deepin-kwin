cmake_minimum_required(VERSION 3.16)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BUILD_SHARED_LIBS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE True)

#add_subdirectory(ki18n)
#add_subdirectory(kconfig)
#add_subdirectory(kcoreaddons)
#add_subdirectory(kcrash) # kcoreaddons
#add_subdirectory(kdbusaddons)
#add_subdirectory(kwindowsystem)
#add_subdirectory(kauth) # kcoreaddons
#add_subdirectory(kglobalaccel) # kconfig kcrash kwindowsystem kdbusaddons kcoreaddons
#add_subdirectory(kidletime)

find_package(KF6 ${KF6_MIN_VERSION} REQUIRED COMPONENTS
    CoreAddons
    I18n
)
# find_package(KF6 ${KF_DEP_VERSION} REQUIRED
#     COMPONENTS
#         Activities
#         Archive
#         Config
#         ConfigWidgets
#         CoreAddons
#         DBusAddons
#         Declarative
#         GlobalAccel
#         GuiAddons
#         I18n
#         IconThemes
#         KIO
#         WindowSystem
#         XmlGui
#         Notifications
#         Package
#         Kirigami2
#     OPTIONAL_COMPONENTS
#         Wayland
#         DocTools
# )
add_subdirectory(kdecoration) # ki18n kcoreaddons
#add_subdirectory(plasma-framework)
