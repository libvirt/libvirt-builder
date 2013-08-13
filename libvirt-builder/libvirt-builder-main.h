/*
 * libvirt-builder-main.h: libvirt builder integration
 *
 * Copyright (C) 2012, 2013 Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * Author: Daniel P. Berrange <berrange@redhat.com>
 *         Christophe Fergeau <cfergeau@redhat.com>
 */

#if !defined(__LIBVIRT_BUILDER_H__) && !defined(LIBVIRT_BUILDER_BUILD)
#error "Only <libvirt-builder/libvirt-builder.h> can be included directly."
#endif

#ifndef __LIBVIRT_BUILDER_MAIN_H__
#define __LIBVIRT_BUILDER_MAIN_H__

G_BEGIN_DECLS

void gvir_builder_init(int *argc,
                       char ***argv);
gboolean gvir_builder_init_check(int *argc,
                                 char ***argv,
                                 GError **err);

G_END_DECLS

#endif /* __LIBVIRT_BUILDER_MAIN_H__ */
