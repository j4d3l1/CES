#include "recording.h"

Recording::Recording(int current, int frequency, QString wave, QDateTime start, QDateTime end);
{
    rCurrent = current;
    rFrequency = frequency;
    rWaveForm = wave;
    startTime = start;
    endTime = end;
    duration = start.secTo(&end);
}
