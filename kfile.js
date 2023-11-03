let project = new Project("Pac-Man");

project.kore = false

project.addFile("TheGame/**");

project.setDebugDir("Deployment");

project.addIncludeDir("Engine/includes");

project.addIncludeDir("TheGame/includes")

project.flatten();

const otherproj = await project.addProject("Engine")

otherproj.addProvider(project,true);

resolve(project);