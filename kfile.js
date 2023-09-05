let project = new Project();

project.addFile("TheGame/**");

project.setDebugDir("Deployment");

project.flatten();

resolve(project);