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
end

def creaURLForma(nombre)
    if(name == "ho-oh")
        return nombre 
    end
    split = nombre.split("-")
    nombre = split[1]
    forma = parseForma(split[0])
    exceso = ""
    if(split.length() == 3)
        exceso = split[2]
    end
    url = ""
    if(nombre == "mime")
        url = forma + "-" + nombre
    elsif (nombre == "mr")
        url = nombre + "-" + exceso + "-" + forma
    else
        url = nombre + "-" + forma
        if(split.length() == 3)
            url += "-" + exceso
        end
    end
    return url
end

def createPokemonFile(filename, gen)
    file = File.open(filename, "r")
    data = file_data = file.readlines.map(&:chomp)
    data.each{ |poke|
        if(File.file?("../Resources/#{gen}/#{poke}.txt"))
            next
        end
        if(poke.split("-").length >= 2)
            poke = creaURLForma(poke)
        end
        agent = Mechanize.new 
        url = "https://pokeapi.co/api/v2/pokemon/"
        begin
            page = agent.get(url + poke + "/")
        rescue Mechanize::ResponseCodeError => e
            puts "Falta #{poke}"
            next 
        end
        p = JSON.parse(page.content)
        type1 = p["types"][0]["type"]["name"]
        type2 = "None"
        begin
            type2 = p["types"][1]["type"]["name"]
        rescue NoMethodError => e
            #puts "Monotype"
        end
        height = p["height"]
        weight = p["weight"]
        statString = "#{poke} #{type1} #{type2} #{gen} #{weight} #{height}"
        File.new("../Resources/#{gen}/#{poke}.txt", "w+")
        File.write("../Resources/#{gen}/#{poke}.txt", statString)
    }
    file.close
end

for i in 1..8
    createPokemonFile("../Resources/#{i}.txt", i)
end
