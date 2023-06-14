require 'fileutils'

def analyze_file(file)
  puts "Analyzing file: #{file}"
  
  # File analysis code in Ruby goes here
  # Example: Get file size
  puts "File size: #{File.size(file)} bytes"
  
  # Example: Get creation time
  creation_time = File.ctime(file)
  puts "Creation time: #{creation_time}"
  
  puts
end

def analyze_directory(directory)
  puts "Analyzing directory: #{directory}"
  
  Dir.foreach(directory) do |entry|
    next if entry == '.' || entry == '..'
    
    path = File.join(directory, entry)
    
    if File.file?(path)
      analyze_file(path)
    elsif File.directory?(path)
      analyze_directory(path)
    end
  end
end

puts 'Enter the directory path to analyze: '
directory_path = gets.chomp

analyze_directory(directory_path)