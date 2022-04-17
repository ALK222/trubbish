#!/usr/bin/env ruby
require 'mechanize'
require 'json'

def parseForma(forma)
    case forma
    when "galarian"
        return "galar"
    when "hisuian"
        return "hisui"
    when "alolan"
        return "alola"
    else
        return forma

end

def creaURLForma(nombre)
    split = nombre.split("-")
    nombre = split[1]
    forma = split[0]
    exceso = ""
    if(lenght(split) == 3)
        exceso = split[2]
    end
    url = ""
    if(nombre == "mime")
        url = forma + "-" + nombre
    elsif (nombre == "mr")
        url = nombre + "-" + exceso + parseForma(forma)
    else
        url = nombre + "-" parseForma(forma)
        if(lenght(split) == 3)
            url += "-" + exceso
        end
    end
    return url
end

def createPokemonFile(filename, gen)
  file = File.open(filename, "r")
  data = file_data = file.readlines.map(&:chomp)
  data.each{ |poke|
        if(lenght(poke.split("-") >= 2)
            poke = creaURLForma(poke)
        end
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
