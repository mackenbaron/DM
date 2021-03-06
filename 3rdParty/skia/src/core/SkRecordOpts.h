/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkRecordOpts_DEFINED
#define SkRecordOpts_DEFINED

#include "SkRecord.h"

// Run all optimizations in recommended order.
void SkRecordOptimize(SkRecord*);

// Turns logical no-op Save-[non-drawing command]*-Restore patterns into actual no-ops.
void SkRecordNoopSaveRestores(SkRecord*);

// For some SaveLayer-[drawing command]-Restore patterns, merge the SaveLayer's alpha into the
// draw, and no-op the SaveLayer and Restore.
void SkRecordNoopSaveLayerDrawRestores(SkRecord*);

// Convert DrawPosText to DrawPosTextH when all the Y coordinates are equal.
void SkRecordReduceDrawPosTextStrength(SkRecord*);

#endif//SkRecordOpts_DEFINED
