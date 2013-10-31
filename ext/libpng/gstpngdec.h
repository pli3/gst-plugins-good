/* GStreamer
 * Copyright (C) <1999> Erik Walthinsen <omega@cse.ogi.edu>
 * Copyright (C) 2012 Collabora Ltd.
 *	Author : Edward Hervey <edward@collabora.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */


#ifndef __GST_PNGDEC_H__
#define __GST_PNGDEC_H__

#include <gst/gst.h>
#include <gst/video/gstvideodecoder.h>
#include <png.h>

G_BEGIN_DECLS

#define GST_TYPE_PNGDEC (gst_pngdec_get_type())
#define GST_PNGDEC(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_PNGDEC,GstPngDec))
#define GST_PNGDEC_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_PNGDEC,GstPngDecClass))
#define GST_IS_PNGDEC(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_PNGDEC))
#define GST_IS_PNGDEC_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_PNGDEC))

typedef struct _GstPngDec GstPngDec;
typedef struct _GstPngDecClass GstPngDecClass;

struct _GstPngDec
{
  GstVideoDecoder parent;

  GstVideoCodecState *input_state;
  GstVideoCodecState *output_state;
  GstVideoCodecFrame *current_frame;

  GstFlowReturn ret;

  /* Progressive */
  GstBuffer *buffer_out;
  png_uint_32 rowbytes;
  
  png_structp png;
  png_infop info;
  png_infop endinfo;

  gint color_type;

  gboolean image_ready;
};

struct _GstPngDecClass
{
  GstVideoDecoderClass parent_class;
};

GType gst_pngdec_get_type(void);

G_END_DECLS

#endif /* __GST_PNGDEC_H__ */
