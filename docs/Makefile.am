DOC_MODULE=libvirt-builder

DOC_MAIN_SGML_FILE=$(DOC_MODULE)-docs.xml

DOC_SOURCE_DIR=$(top_srcdir)/libvirt-builder

SCANGOBJ_OPTIONS=

SCAN_OPTIONS=--rebuild-sections --rebuild-types

MKDB_OPTIONS=--sgml-mode --output-format=xml

MKTMPL_OPTIONS=

MKHTML_OPTIONS=

FIXXREF_OPTIONS=

HFILE_GLOB=$(top_srcdir)/libvirt-builder/*.h
CFILE_GLOB=$(top_srcdir)/libvirt-builder/*.c

IGNORE_HFILES=

HTML_IMAGES=

content_files=

expand_content_files=

GTKDOC_CFLAGS= \
	$(GOBJECT2_CFLAGS) \
	$(LIBOSINFO_CFLAGS) \
	$(LIBVIRT_GCONFIG_CFLAGS) \
	$(LIBVIRT_GOBJECT_CFLAGS)
GTKDOC_LIBS = \
	$(GOBJECT2_LIBS) \
	$(LIBOSINFO_LIBS) \
	$(LIBVIRT_GCONFIG_LIBS) \
	$(LIBVIRT_GOBJECT_LIBS) \
	$(top_builddir)/libvirt-builder/libvirt-builder-1.0.la

include $(top_srcdir)/gtk-doc.make
