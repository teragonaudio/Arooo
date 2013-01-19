/*
  ==============================================================================

    Constants
    Created: 19 Jan 2013 1:55:33pm
    Author:  Nik Reiman

  ==============================================================================
*/

#ifndef __CONSTANTS_H_448F6882__
#define __CONSTANTS_H_448F6882__

static const int kBufferSize = 1024;
static const int kBufferSizeBase2 = 10; // 2^10

static const float kSampleRate = 44100.0f;

// Also check this number of buckets above and below the target bucket index.
// So if the bucket index is 33, this would check buckets 32 & 34.
static const int kBucketTolerance = 1;

// The minimum strength of the bucket value in order to trigger a hit
static const float kBucketMinimumStrength = 20.0f; // TODO: Needs tweaking

// TODO: Would be nice to use real frequencies instead of bucket indexes
// These must be recalibrated for different FFT buffer sizes
static const int kHowlBucketIndexes[] = { 14, 32, 526 };
static const int kHowlBucketNumIndexes = 3;

// If all buckets have at least this many hits, a howl has been found
static const int kHowlDetectionNumPointsNeeded = 15;

static const int kOutputMidiChannel = 1;
static const int kOutputMidiNoteNumber = 64;
static const int kOutputMidiNoteVelocity = 127;
static const int kOutputMidiNoteDurationMs = 1000;

#endif  // __CONSTANTS_448F6882__
