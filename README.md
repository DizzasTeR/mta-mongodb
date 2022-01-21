# MTA MongoDB Module
Allow connections to mongodb!

# Credits
[neoxic](https://github.com/neoxic) for the lua module. I basically took his project and set it up for mta.

# Documentation
https://github.com/neoxic/lua-mongo/tree/master/doc

Check out different readmes here for understanding the module api

# Download
Check out [Releases](https://github.com/DizzasTeR/mta-mongodb/releases)

# Installing the module
## 64-bit
- Copy the built module (DMongoDB.dll or libDMongoDB.so depending on your operating system)
- Paste it in *YOUR_MTA_SERVER_DIRECTORY/x64/modules/* (Create the folders if they don't exist)

## 32-bit
- Copy the built module (DMongoDB32.dll or libDMongoDB32.so depending on your operating system)
- Paste it in *YOUR_MTA_SERVER_DIRECTORY/mods/deathmatch/modules/* (Create the folders if they don't exist)

# Loading the module
- You have the following ways

## MTA server config
- Inside the server config, search for module
- You can see example code in the config to load modules on server start-up
- Example: 
```xml
<!-- 64-bit -->
<module src="DMongoDB.dll"/>

<!-- 32-bit -->
<module src="DMongoDB32.dll"/>
```
OR
```xml
<!-- 64-bit -->
<module src="libDMongoDB.so"/>

<!-- 32-bit -->
<module src="libDMongoDB32.so"/>
```

## Load from server console
- Run loadmodule DMongoDB.dll OR loadmodule libDMongoDB.so depending on your OS to load the module