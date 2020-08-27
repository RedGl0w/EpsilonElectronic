apps += Electronic::App
app_headers += apps/electronic/app.h

app_electronic_src = $(addprefix apps/electronic/,\
  app.cpp \
  menu_controller.cpp \
  electronic_controller.cpp \
)

electronic_law = $(addprefix apps/electronic/,\
  ohm \
)

$(foreach i,${electronic_law},$(eval include $(i)/Makefile))

electronic_shared = $(addprefix apps/electronic/shared/, \
  battery_view.cpp \
  resistor_view.cpp \
  cable_view.cpp \
  current_view.cpp \
)

apps_src += $(app_electronic_src)
apps_src += $(electronic_shared)

i18n_files += $(call i18n_without_universal_for,electronic/base)


$(eval $(call depends_on_image,apps/electronic/app.cpp,apps/electronic/electronic_icon.png))
