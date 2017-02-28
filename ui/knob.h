#ifndef __INAUDIBLE_KNOB_H__
#define __INAUDIBLE_KNOB_H__

#include <gdk/gdk.h>
#include <gtk/gtk.h>
#include <math.h>

G_BEGIN_DECLS

#define INAUDIBLE_TYPE_KNOB          (inaudible_knob_get_type())
#define INAUDIBLE_KNOB(obj)          (G_TYPE_CHECK_INSTANCE_CAST ((obj), INAUDIBLE_TYPE_KNOB, InaudibleKnob))
#define INAUDIBLE_IS_KNOB(obj)       (G_TYPE_CHECK_INSTANCE_TYPE ((obj), INAUDIBLE_TYPE_KNOB))
#define INAUDIBLE_KNOB_CLASS(klass)  (G_TYPE_CHECK_CLASS_CAST ((klass),  INAUDIBLE_TYPE_KNOB, InaudibleKnobClass))
#define INAUDIBLE_IS_KNOB_CLASS(obj) (G_TYPE_CHECK_CLASS_TYPE ((klass), INAUDIBLE_TYPE_KNOB))

typedef struct _InaudibleKnob        InaudibleKnob;
typedef struct _InaudibleKnobPrivate InaudibleKnobPrivate;
typedef struct _InaudibleKnobClass   InaudibleKnobClass;

struct _InaudibleKnob
{
	gfloat minimumValue;
	gfloat maximumValue;
    GtkRange parent;
	GdkPixbuf* cursor;

    InaudibleKnobPrivate* priv;
};

struct _InaudibleKnobClass
{
	GtkRangeClass parent_class;
};

GtkWidget*	        inaudible_knob_new(void);
GType		        inaudible_knob_get_type(void); G_GNUC_CONST

gfloat		        inaudible_knob_get_value(InaudibleKnob* knob);
void                inaudible_knob_set_value(InaudibleKnob* knob, gfloat value);
void 		        inaudible_knob_set_size (InaudibleKnob* knob, gint size);

static void         inaudible_knob_class_init(InaudibleKnobClass* klass);
static void         inaudible_knob_init(InaudibleKnob* knob);
static gboolean     inaudible_knob_value_changed(gpointer obj);
void                inaudible_knob_size_allocate(GtkWidget* widget, GdkRectangle* allocation);

GType               inaudible_knob_get_type(void);
GtkWidget*          inaudible_knob_new(void);
void                inaudible_knob_set_size(InaudibleKnob* knob, gint size);

G_END_DECLS

#endif