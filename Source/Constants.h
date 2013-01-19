/*
  ==============================================================================

    Constants
    Created: 19 Jan 2013 1:55:33pm
    Author:  Nik Reiman

  ==============================================================================
*/

#ifndef __CONSTANTS_H_448F6882__
#define __CONSTANTS_H_448F6882__

// TODO: Use static consts

#define BUFFER_SIZE 1024
#define BUFFER_SIZE_BASE 10 // 2^10

#define SAMPLE_RATE 44100.0

// Also check this number of buckets above and below the target bucket index.
// So if the bucket index is 33, this would check buckets 32 & 34.
#define BUCKET_TOLERANCE 1

// The minimum strength of the bucket value in order to trigger a hit
#define BUCKET_MINIMUM_STRENGTH 20.0f // TODO: Needs tweaking

// TODO: Would be nice to use real frequencies instead of bucket indexes
// These must be recalibrated for different FFT buffer sizes
static const int kHowlBucketIndexes[] = { 14, 32, 526 };
#define BUCKET_NUM_INDEXES 3

// If all buckets have at least this many hits, a howl has been found
#define HOWL_FOUND_NUM_HITS 10

// TODO: Naming
static const int OUTPUT_MIDI_CHANNEL = 1;
static const int OUTPUT_MIDI_NOTE_NUMBER = 64;
static const int OUTPUT_MIDI_NOTE_VELOCITY = 127;
static const int OUTPUT_NOTE_LENGTH_IN_MS = 250;

#endif  // __CONSTANTS_448F6882__
