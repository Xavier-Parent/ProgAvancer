let project = new Project("Solomons Key");

project.kore = false

project.addFile("TheGame/**");

project.setDebugDir("Deployment");

project.addIncludeDir("Engine/includes");

project.flatten();

const otherproj = await project.addProject("Engine")

otherproj.addProvider(project,true);

resolve(project);