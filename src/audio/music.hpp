#pragma once

#include <SFML/Audio/Music.hpp>
#include <queue>

class Music : public sf::Music {
public:
    typedef sf::Music super;
    typedef std::pair<std::string, bool> MusicItem;

    static const bool LOOP;
    static const bool NO_LOOP;

    static void Enqueue(const std::string& file, bool loop);
    static void Update(double delta);
    static void PlayNext();
    static void FadeOut(float duration);
    static void ClearQueue();

protected:
    bool onGetData(SoundStream::Chunk& data);

private:
    static Music music_;
    static std::queue<MusicItem> music_queue_;
    static float accum_;
    static bool fade_enabled_;
    static float fade_speed_;
};
