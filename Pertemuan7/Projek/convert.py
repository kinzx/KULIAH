from moviepy.editor import VideoFileClip

# Input and output file paths
input_file = "input_video.mp4"  # Replace with your MP4 file path
output_file = "output_audio.mp3"  # Desired MP3 file path

# Load the video file
video = VideoFileClip(input_file)

# Extract audio and save as MP3
video.audio.write_audiofile(output_file)

print(f"Audio extracted and saved as: {output_file}")
