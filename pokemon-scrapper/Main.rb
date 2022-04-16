#!/usr/bin/env ruby
require 'mechanize'
require 'json'

def createPokemonFile(filename, gen)
  file = File.open(filename, "r")
  data = file_data = file.readlines.map(&:chomp)
  data.each{ |poke|
        agent = Mechanize.new 
        url = "https://pokeapi.co/api/v2/pokemon/"
        page = agent.get(url + poke + "/")
        p = JSON.parse(page.content)
        type1 = p["types"][0]["type"]["name"]
        type2 = "None"
        begin
            type2 = p["types"][1]["type"]["name"]
        rescue NoMethodError => e
            puts "Monotype"
        end
        height = p["height"]
        weight = p["weight"]
        statString = "#{poke} #{type1} #{type2} #{gen} #{weight} #{height}"
        File.new("../Resources/#{gen}/#{poke}.txt", "w+")
        File.write("../Resources/#{gen}/#{poke}.txt", statString)
    }
  file.close
end

for i in 1..1
    createPokemonFile("../Resources/#{i}.txt", i)
end
