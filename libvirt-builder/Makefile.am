
EXTRA_DIST = libvirt-builder.sym
CLEANFILES =

lib_LTLIBRARIES = libvirt-builder-1.0.la

BUILDER_TEMPLATE_FILES = \
			libvirt-builder-enum-types.h.template \
			libvirt-builder-enum-types.c.template \
			$(NULL)

BUILDER_GENERATED_ENUM_FILES = \
			libvirt-builder-enum-types.h \
			libvirt-builder-enum-types.c \
			$(NULL)

BUILDER_GENERATED_FILES = \
			$(BUILDER_GENERATED_ENUM_FILES) \
			$(NULL)

BUILDER_HEADER_FILES = \
			libvirt-builder.h \
			libvirt-builder-internal.h \
			libvirt-builder-main.h \
			$(NULL)
BUILDER_SOURCE_FILES = \
			libvirt-builder-main.c \
			$(NULL)

libvirt_builder_1_0_ladir = $(includedir)/libvirt-builder-1.0/libvirt-builder
libvirt_builder_1_0_la_HEADERS = \
			$(BUILDER_HEADER_FILES)
libvirt_builder_1_0_la_SOURCES = \
			$(BUILDER_SOURCE_FILES)
nodist_libvirt_builder_1_0_la_HEADERS = \
			libvirt-builder-enum-types.h
			$(NULL)
nodist_libvirt_builder_1_0_la_SOURCES = \
			libvirt-builder-enum-types.c \
			$(NULL)
libvirt_builder_1_0_la_CFLAGS = \
			-DBINDIR="\"$(bindir)\"" \
			-DDATADIR="\"$(datadir)\"" \
			-DLIBVIRT_BUILDER_BUILD \
			-DLIBEXECDIR="\"$(libexecdir)\"" \
			-DRUNDIR="\"$(rundir)\"" \
			$(COVERAGE_CFLAGS) \
			-I$(top_srcdir) \
			$(GLIB2_CFLAGS) \
			$(WARN_CFLAGS) \
			$(NULL)
libvirt_builder_1_0_la_LIBADD = \
			$(GLIB2_LIBS) \
			$(CYGWIN_EXTRA_LIBADD) \
			$(NULL)
libvirt_builder_1_0_la_DEPENDENCIES = \
                        libvirt-builder.sym
libvirt_builder_1_0_la_LDFLAGS = \
			$(WARN_CFLAGS) \
			$(COVERAGE_CFLAGS:-f%=-Wc,f%) \
			$(CYGWIN_EXTRA_LDFLAGS) \
			$(MINGW_EXTRA_LDFLAGS) \
			-Wl,--version-script=$(srcdir)/libvirt-builder.sym \
			-version-info $(LIBVIRT_BUILDER_VERSION_INFO)


EXTRA_DIST += $(BUILDER_TEMPLATE_FILES)

BUILT_SOURCES = $(BUILDER_GENERATED_FILES)
CLEANFILES += $(BUILDER_GENERATED_FILES)

libvirt-builder-enum-types.h: $(BUILDER_HEADER_FILES) libvirt-builder-enum-types.h.template
	$(AM_V_GEN) ( $(GLIB_MKENUMS) --template $(srcdir)/libvirt-builder-enum-types.h.template $(BUILDER_HEADER_FILES:%=$(srcdir)/%) ) | \
            sed -e "s/G_TYPE_VIR_CONFIG/GVIR_CONFIG_TYPE/" -e "s/g_vir/gvir/" > libvirt-builder-enum-types.h

libvirt-builder-enum-types.c: $(BUILDER_HEADER_FILES) libvirt-builder-enum-types.c.template
	$(AM_V_GEN) ( $(GLIB_MKENUMS) --template $(srcdir)/libvirt-builder-enum-types.c.template $(BUILDER_HEADER_FILES:%=$(srcdir)/%) ) | \
            sed -e "s/G_TYPE_VIR_CONFIG/GVIR_CONFIG_TYPE/" -e "s/g_vir/gvir/" > libvirt-builder-enum-types.c

check_PROGRAMS =

TESTS = $(check_PROGRAMS)

if WITH_INTROSPECTION

LibvirtBuilder-1.0.gir: libvirt-builder-1.0.la $(G_IR_SCANNER) Makefile.am
	$(AM_V_GEN) $(G_IR_SCANNER) \
                --quiet \
                --warn-all \
                --namespace LibvirtBuilder \
                --nsversion 1.0 \
                --include Libosinfo-1.0 \
                --include LibvirtGConfig-1.0 \
                --identifier-prefix=GVirBuilder \
                --symbol-prefix=gvir_builder \
                --library=$(builddir)/libvirt-builder-1.0.la \
                --output $@ \
                -I$(top_srcdir) \
                -I$(top_builddir) \
                --verbose \
                --pkg=libosinfo-1.0 \
                --pkg=libvirt-gconfig-1.0 \
                --c-include="libvirt-builder/libvirt-builder.h" \
                --pkg-export=libvirt-builder-1.0 \
                $(srcdir)/libvirt-builder.h \
                $(BUILDER_SOURCE_FILES:%=$(srcdir)/%) \
                $(BUILDER_HEADER_FILES:%=$(srcdir)/%) \
                $(BUILDER_GENERATED_ENUM_FILES:%=%) \
                $(NULL)

girdir = $(datadir)/gir-1.0
gir_DATA = LibvirtBuilder-1.0.gir

typelibsdir = $(libdir)/girepository-1.0
typelibs_DATA = LibvirtBuilder-1.0.typelib

%.typelib: %.gir
	$(AM_V_GEN)$(G_IR_COMPILER) \
                --includedir=$(builddir) \
                --includedir=$(girdir) \
                -o $@ $<

CLEANFILES += $(gir_DATA) $(typelibs_DATA)

endif # WITH_INTROSPECTION
