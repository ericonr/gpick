/*
 * Copyright (c) 2009-2016, Albertas Vyšniauskas
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 *     * Neither the name of the software author nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef GPICK_GTK_COLOR_COMPONENT_H_
#define GPICK_GTK_COLOR_COMPONENT_H_

#include <gtk/gtk.h>
#include "Color.h"

#define GTK_TYPE_COLOR_COMPONENT (gtk_color_component_get_type())
#define GTK_COLOR_COMPONENT(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GTK_TYPE_COLOR_COMPONENT, GtkColorComponent))
#define GTK_COLOR_COMPONENT_CLASS(obj) (G_TYPE_CHECK_CLASS_CAST((obj), GTK_COLOR_COMPONENT, GtkColorComponentClass))
#define GTK_IS_COLOR_COMPONENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), GTK_TYPE_COLOR_COMPONENT))
#define GTK_IS_COLOR_COMPONENT_CLASS(obj) (G_TYPE_CHECK_CLASS_TYPE((obj), GTK_TYPE_COLOR_COMPONENT))
#define GTK_COLOR_COMPONENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), GTK_TYPE_COLOR_COMPONENT, GtkColorComponentClass))

struct GtkColorComponent
{
	GtkDrawingArea parent;
};
struct GtkColorComponentClass
{
	GtkDrawingAreaClass parent_class;
	void (*color_changed)(GtkWidget* widget, Color* c, gpointer userdata);
	void (*input_clicked)(GtkWidget* widget, int component_id, gpointer userdata);
};
enum class GtkColorComponentComp: int
{
	rgb,
	hsv,
	hsl,
	cmyk,
	xyz,
	lab,
	lch,
};
GtkWidget* gtk_color_component_new(GtkColorComponentComp component);
void gtk_color_component_set_color(GtkColorComponent* color_component, Color* color);
void gtk_color_component_set_text(GtkColorComponent* color_component, const char **text);
const char* gtk_color_component_get_text(GtkColorComponent* color_component, gint component_id);
void gtk_color_component_set_label(GtkColorComponent* color_component, const char **label);
void gtk_color_component_get_color(GtkColorComponent* color_component, Color* color);
void gtk_color_component_get_raw_color(GtkColorComponent* color_component, Color* color);
void gtk_color_component_set_raw_color(GtkColorComponent* color_component, Color* color);
void gtk_color_component_get_transformed_color(GtkColorComponent* color_component, Color* color);
void gtk_color_component_set_transformed_color(GtkColorComponent* color_component, Color* color);
void gtk_color_component_set_out_of_gamut_mask(GtkColorComponent* color_component, bool mask_enabled);
bool gtk_color_component_get_out_of_gamut_mask(GtkColorComponent* color_component);
void gtk_color_component_set_lab_illuminant(GtkColorComponent* color_component, ReferenceIlluminant illuminant);
void gtk_color_component_set_lab_observer(GtkColorComponent* color_component, ReferenceObserver observer);
GtkColorComponentComp gtk_color_component_get_component(GtkColorComponent* color_component);
int gtk_color_component_get_component_id_at(GtkColorComponent* color_component, gint x, gint y);
GType gtk_color_component_get_type();

#endif /* GPICK_GTK_COLOR_COMPONENT_H_ */
