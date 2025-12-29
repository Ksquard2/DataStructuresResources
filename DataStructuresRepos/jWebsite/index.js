const stages = document.querySelectorAll(".stage");

stages.forEach(stage =>
{
    const panel = stage.querySelector(".panel");
    const rotator = stage.querySelector(".rotator");
    const audio = new Audio(stage.dataset.audio);
    audio.loop = true;
    audio.currentIndex = 0;
    audio.lyrics = null;  
    let isPlaying = false;

    audio.addEventListener("timeupdate", function()
    {
        if (!audio.lyrics) return; // nothing to do if lyrics not loaded
        const nextIndex = audio.currentIndex + 1;
        
        if (nextIndex < audio.lyrics.length && audio.currentTime >= audio.lyrics[nextIndex].time)
        {
            audio.currentIndex = nextIndex;
            panel.querySelector(".lyrics").textContent = audio.lyrics[audio.currentIndex].text;
        }
    });

    rotator.addEventListener("click", async function()
    {
        isPlaying = !isPlaying;

        if (isPlaying)
        {
            // shift forward
            stage.classList.add("active");
            rotator.style.animationPlayState = "running";
            audio.play();
            fadeAudio(audio, 1, 800);

            // load lyrics only once
            if (!audio.lyrics)
            {
                const lyricsString = await getLyrics(panel.dataset.artist, panel.dataset.title);
                audio.lyrics = parseLRC(lyricsString);
                panel.querySelector(".lyrics").textContent = audio.lyrics[0]?.text || "No lyrics found";
                console.log("Lyrics loaded and synced!");
            }
        }
        else
        {
            // shift back
            stage.classList.remove("active");
            rotator.style.animationPlayState = "paused";
            fadeAudio(audio, 0, 800);
        }
    });
});


// if you click too fast, this kinda breaks

function fadeAudio(audio, target, duration)
{
    const stepTime = 50;
    const steps = duration / stepTime;
    const volumeStep = (target - audio.volume) / steps;
    
    let i = 0;
    const fadeInterval = setInterval(() =>
    {
        audio.volume = Math.min(Math.max(audio.volume + volumeStep, 0), 1);
        i++;
        if (i >= steps)
        {
            clearInterval(fadeInterval);
            if (target === 0) audio.pause();
        }
    }, stepTime);
}


//--------------------------------------------------------------------------------------
// This function solely focuses on getting the lyrics for a given song using an API call
//--------------------------------------------------------------------------------------

async function getLyrics(artist, title)
{
    const query = encodeURIComponent(artist + " " + title);
    const url = `https://lrclib.net/api/search?q=${query}`;

    try
    {
        const response = await fetch(url);
        if (!response.ok) throw new Error("Lyrics Not Found");
        let songData = await response.json();

        let lyrics = null;
        for (let i = 0; i < songData.length; i++)
        {
            if (songData[i].artistName.toLowerCase() === artist.toLowerCase() &&
                songData[i].trackName.toLowerCase() === title.toLowerCase() &&
                songData[i].syncedLyrics) 
            {
                lyrics = songData[i].syncedLyrics;
                break;
            }
        }
        return lyrics;
    }
    catch (error)
    {
        throw error;
    }
}


//--------------------------------
// parses the lyrics into an array
//--------------------------------

function parseLRC(lrcString)
{
    const lines = lrcString.split("\n");
    const lyrics = [];
    const timeRegex = /\[(\d+):(\d+\.\d+)\]/; // matches [mm:ss.xx]

    lines.forEach(line =>
    {
        const match = line.match(timeRegex);
        if (match)
        {
            const minutes = parseInt(match[1], 10);
            const seconds = parseFloat(match[2]);
            const time = minutes * 60 + seconds;
            const text = line.replace(timeRegex, "").trim();
            lyrics.push({ time, text });
        }
    });

    return lyrics;
}



//----------------------------------------------
// This will handle the navigation bar animation
//----------------------------------------------

const navBar = document.querySelector(".navBar");
const bubble = document.querySelector(".bubble");
const bubbleMove = document.querySelector(".bubblePos");

let isOpen = false;
bubble.addEventListener("click", function() {
    isOpen = !isOpen;

    if (isOpen)
    {
        //shift forward
        console.log("clicked");
        bubbleMove.classList.add("active");
        navBar.classList.add("active");
    }
    else
    {
        // shift back
        console.log("closing");
        bubbleMove.classList.remove("active");
        navBar.classList.remove("active");
    }
});