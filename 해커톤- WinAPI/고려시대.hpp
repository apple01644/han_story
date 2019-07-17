void ����ô�(EventManager& evt_mng) {

	{
		EventMaker e("���ο� �ô� ź��", EventPriority::Normal);

		e->content =
			"�����ð� ���� ȣ������ �븳�� �ձ��� ��ȭ �������� ���з�\n\
			�Ŷ�� ������ ������ ���� �Ǿ����ϴ�.\n\
������ �ѹݵ��� �������� ������������ �ݵ�� ���յǾ�� �մϴ�\n\
��� ������� �Ļﱹ�� ���� �� ���Դϱ�?";

		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "����ô�") return false;
			if (data.dict["���ź��"] == "")
			{
				data.dict["���ź��"] = "���۵�";
				return true;
			}
			else
				return false;
		};

		{
			EventSelectItemMaker s(e, "�Ŷ�� ���� ��� �Ĺ����� ����ģ��.");
			s->content =
				"�Ŷ� �Ĺ������� ���ݹ޾Ƶ����ݴϴ�.\n\
�ڱ�-\n\
�η�-";
			s->CanRun = [&](Gamedata& data) {
				return (data.player.res.money >= 2 && data.player.res.human >= 4);
			};

			s->Effect = [&](Gamedata& data) {
				data.dict["���ź��"] = "������";
				data.player.res.money -= 2;
				data.player.res.human -= 4;
			};
		}
		{
			EventSelectItemMaker s(e, "���븦 ������ ���� ȣ������ ��������� �����ϴ�.");
			s->content =
				"���븦 ������ ȣ������ �ڽ��� ������ �����ϴ�..\n\
�ڱ�-\n\
�ķ�-\n\
�ž�+";
			s->CanRun = [&](Gamedata& data) {
				return (data.player.res.money >= 1 && data.player.res.food >= 2);
			};

			s->Effect = [&](Gamedata& data) {
				data.dict["���ź��"] = "������";
				data.player.res.money -= 1;
				data.player.res.food -= 2;
				data.player.res.faith += 2;
			};
		}
	}

	{
		EventMaker e("���ο� ������", EventPriority::Normal);

		e->content =
			"ȣ������ ģ���� �׾ƾ� �� ������ ���� �ɼ��ֽ��ϴ�.\n\
ȣ����� ��� ģ���� ���� ���Դϱ�?";

		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "����ô�") return false;
			if (data.dict["���ź��"] == "������")
			{
				data.dict["���ź��"] = "�� ź��";
				return true;
			}
			else
				return false;
		};

		{
			EventSelectItemMaker s(e, "��ɰ� ������ �ǽ��մϴ�.");
			s->content =
				"���� ���� ������ ������ �� ������ �ٽ����� �ϴ� ��ɰ� ������ �ǽ��մϴ�.\n\
�ڱ�+\n\
�η�+\n\
�ܱ���-";
			s->CanRun = [&](Gamedata& data) {
				return data.player.res.diplo >= 2;
			};

			s->Effect = [&](Gamedata& data) {
				data.dict["���ź��"] = "��������";
				data.player.res.human += 2;
				data.player.res.money += 1;
				data.player.res.diplo -= 2;
			};
		}
		{
			EventSelectItemMaker s(e, "�缺��å�� �ǽ��մϴ�.");
			s->content =
				"ȣ���鿡�� ������ ������ �־����� ������ ���� �־����ϴ�.\n\
�η�+\n\
�ž�+\n\
�ڱ�-";
			s->CanRun = [&](Gamedata& data) {
				return data.player.res.money >= 2;
			};

			s->Effect = [&](Gamedata& data) {
				data.dict["���ź��"] = "��������";
				data.player.res.money -= 1;
				data.player.res.human += 1;
				data.player.res.faith += 2;
			};
		}
		{
			EventSelectItemMaker s(e, "ȥ�������� �����մϴ�.");
			s->content =
				"���� ���� ������ȥ�� �մϴ�..\n\
�η�-\n\
�ķ�+";
			s->CanRun = [&](Gamedata& data) {
				return data.player.res.human >= 2;
			};

			s->Effect = [&](Gamedata& data) {
				data.dict["���ź��"] = "��������";
				data.player.res.human -= 1;
				data.player.res.food += 2;
			};
		}
		{
			EventSelectItemMaker s(e, "�ƹ������� �������� �ʽ��ϴ�.");
			s->content =
				"���� ������ �������� �ʾƵ� �ȴٰ� �����մϴ�.\n\
�ܱ���-\n\
�η�-";
			s->CanRun = [&](Gamedata& data) {
				return (data.player.res.diplo >= 2 && data.player.res.human >= 2);
			};

			s->Effect = [&](Gamedata& data) {
				data.dict["���ź��"] = "��������";
				data.player.res.diplo -= 2;
				data.player.res.human -= 2;
			};
		}
	}

	//����ô뿡 ��������
	{
		EventMaker e("����ô뿡 ��������", EventPriority::Normal);

		e->content =
			"�߱����� ��ȭ�� �ֱⰡ ���ο� ������ ��õ�Ͽ����ϴ�.";

		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "����ô�") return false;
			if (data.dict["���ź��"] == "��������")
			{
				data.dict["���ź��"] = "��������";
				return true;
			}
			else
				return false;
		};

		{
			EventSelectItemMaker s(e, "�ֱ��� �ǰ��� ���� �����Ѵ�.");
			s->content =
				"���󿡼� ������ ġ�� �ɷ��ִ� ������ �����Ҽ��ֽ��ϴ�.\n\
�ڱ�-\n\
�η�+";
			s->CanRun = [&](Gamedata& data) {
				return data.player.res.money >= 2;
			};

			s->Effect = [&](Gamedata& data) {
				data.dict["���ź��"] = "���ڰ�";
				data.player.res.human += 4;
				data.player.res.money -= 2;
			};
		}
		{
			EventSelectItemMaker s(e, "�ֱ��� �ǰ��� �ݴ��մϴ�.");
			s->content =
				"������ �����մϴ�.\n\
�η�-\n\
�����+";
			s->CanRun = [&](Gamedata& data) {
				return data.player.res.human >= 2;
			};

			s->Effect = [&](Gamedata& data) {
				data.dict["���ź��"] = "���ڰ�";
				data.player.res.milli += 1;
				data.player.res.human -= 2;
			};
		}
		{
			EventSelectItemMaker s(e, "������ ������ ����� �����ϰڴ�!");
			s->content =
				"������ ������ �ֱ��� ������ ������ �����ʽ��ϴ�.\n\
���� ������ ��� ������� �̴� ������ ������Դϴ�.\n\
�η�-\n\
�ž�-";
			s->CanRun = [&](Gamedata& data) {
				return (data.player.res.human >= 2 && data.player.res.faith >= 3);
			};

			s->Effect = [&](Gamedata& data) {
				data.dict["���ź��"] = "���ڰ�";
				data.player.res.human -= 2;
				data.player.res.faith -= 3;
			};
		}
	}

	//����� ���ڰ�
	{
		EventMaker e("����� ���ڰ�", EventPriority::Normal);

		e->content =
			"����� ������ �⼧��Ű������ ���ڰ��� �������ΰ���?.";

		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "����ô�") return false;
			if (data.dict["���ź��"] == "���ڰ�")
			{
				data.dict["���ź��"] = "���ڰ� ����";
				return true;
			}
			else
				return false;
		};

		{
			EventSelectItemMaker s(e, "���ڰ��� ��ġ�Ұ��Դϴ�.");
			s->content =
				"����� ������� �����ɷ��� ���� �� �ֽ��ϴ�.\n\
�ڱ�-\n\
�ܱ���+\n\
�����+";
			s->CanRun = [&](Gamedata& data) {
				return data.player.res.money >= 2;
			};

			s->Effect = [&](Gamedata& data) {
				data.dict["���ź��"] = "����õ��";
				data.player.res.milli += 3;
				data.player.res.diplo += 3;
				data.player.res.money -= 2;
			};
		}
		{
			EventSelectItemMaker s(e, "���ڰ��� ��ġ���� �ʽ��ϴ�.");
			s->content =
				"������ �����մϴ�.";

			s->Effect = [&](Gamedata& data) {
				data.dict["���ź��"] = "����õ��";
			};
		}
	}

	//����õ���
	{
		EventMaker e("����õ���", EventPriority::Normal);

		e->content =
			"�̺�Ʈ �����Դϴ�!\n\
����õ����� �̸�Ų �ι��� �����Դϱ�?";

		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "����ô�") return false;
			if (data.dict["���ź��"] == "����õ��")
			{
				data.dict["���ź��"] = "����õ���";
				return true;
			}
			else
				return false;
		};

		{
			EventSelectItemMaker s(e, "��û�� �����׽��ϴ�.");
			s->content =
				"��¥ ��û�� �����״ٰ� �����Ͻʴϱ�?\nƲ���� ���� ��鸱���Դϴ�";

			s->Effect = [&](Gamedata& data) {
				data.dict["���ź��"] = "�������";
				data.player.res.food += 5;
				data.player.res.human += 5;
				data.player.res.money += 5;
				data.player.res.diplo += 5;
				data.player.res.milli += 5;
				data.player.res.faith += 5;
			};
		}
		{
			EventSelectItemMaker s(e, "��ν��� �����׽��ϴ�.");
			s->content =
				"��¥ ��ν��� �����״ٰ� �����Ͻʴϱ�?\nƲ���� ���� ��鸱���Դϴ�";

			s->CanRun = [&](Gamedata& data) {
				return (data.player.res.food >= 5 && data.player.res.human >= 5 && data.player.res.money >= 5 && data.player.res.faith >= 5 && data.player.res.milli >= 5 && data.player.res.diplo >=5);
			};

			s->Effect = [&](Gamedata& data) {
				data.dict["���ź��"] = "�������";
				data.player.res.food -= 5;
				data.player.res.human -= 5;
				data.player.res.money -= 5;
				data.player.res.diplo -= 5;
				data.player.res.milli -= 5;
				data.player.res.faith -= 5;
			};
		}
		{
			EventSelectItemMaker s(e, "������ �����׽��ϴ�.");
			s->content =
				"��¥ ������ �����״ٰ� �����Ͻʴϱ�?\nƲ���� ���� ��鸱���Դϴ�";
			s->CanRun = [&](Gamedata& data) {
				return (data.player.res.food >= 5 && data.player.res.human >= 5 && data.player.res.money >= 5 && data.player.res.faith >= 5 && data.player.res.milli >= 5 && data.player.res.diplo >= 5);
			};

			s->Effect = [&](Gamedata& data) {
				data.dict["���ź��"] = "�������";
				data.player.res.food -= 5;
				data.player.res.human -= 5;
				data.player.res.money -= 5;
				data.player.res.diplo -= 5;
				data.player.res.milli -= 5;
				data.player.res.faith -= 5;
			};
		}
	}

	//�������
	{
		EventMaker e("�Ŷ����� ����", EventPriority::Normal);

		e->content =
			"�Ŷ��� �츮���� �����Ϸ��� �մϴ�.\n\
��� �ൿ�Ͻǰ̴ϱ�?";

		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "����ô�") return false;
			if (data.dict["���ź��"] == "�������")
			{
				data.dict["���ź��"] = "������ ����";
				return true;
			}
			else
				return false;
		};

		{
			EventSelectItemMaker s(e, "������ ���ϸ� ���� �ܱ������� �Ұ��Դϴ�.");
			s->content =
				"������ ���ϴ� �ſ� �����Ͽ� ���񿡰� �ּ��� ����� ã�Ƴ����Դϴ�.\n\
�ܱ���++\n\
�����+\n\
�ڱ�-";
			s->CanRun = [&](Gamedata& data) {
				return data.player.res.money >= 1;
			};

			s->Effect = [&](Gamedata& data) {
				data.dict["���ź��"] = "��������";
				data.player.res.milli += 1;
				data.player.res.diplo += 7;
				data.player.res.money -= 1;
			};
		}
		{
			EventSelectItemMaker s(e, "���縦 ��� �Ŷ��� ������ �մϴ�.");
			s->content =
				"���븦 ��� �Ŷ��� ������ �Ͽ� �̰ܺ����� �մϴ�.\n\
������ �Ŷ����� ���� �ʹ� �����ϴ�.\n\
�ܱ���-\n\
�����-\n\
�ķ�-";

			s->CanRun = [&](Gamedata& data) {
				return (data.player.res.diplo >= 4 && data.player.res.milli >=2 && data.player.res.food >= 1);
			};

			s->Effect = [&](Gamedata& data) {
				data.dict["���ź��"] = "��������";
				data.player.res.milli -= 2;
				data.player.res.diplo -= 4;
				data.player.res.food -= 1;
			};
		}
		{
			EventSelectItemMaker s(e, "�׳� ������ �ֽ��ϴ�.");
			s->content =
				"�Ŷ��� ħ���Ͽ����ϴ�.\n\
�ķ�--\n\
�η�--\n\
�ڱ�--\n\
�ž�--\n\
�����--\n\
�ܱ���--";

			s->CanRun = [&](Gamedata& data) {
				return (data.player.res.food >= 10000 && data.player.res.human >= 10000 && data.player.res.money >= 10000 && data.player.res.faith >= 10000 && data.player.res.milli >= 10000 && data.player.res.diplo >= 10000);
			};

			s->Effect = [&](Gamedata& data) {
				data.dict["���ź��"] = "��������";
				data.player.res.food -= 10000;
				data.player.res.human -= 10000;
				data.player.res.money -= 10000;
				data.player.res.diplo -= 10000;
				data.player.res.milli -= 10000;
				data.player.res.faith -= 10000;
			};
		}
	}

	//��������
	{
		EventMaker e("��������", EventPriority::Normal);

		e->content =
			"���ŵ��� ������ �����׽��ϴ�.\n\
�� ���ŵ��� ������ �����״ٰ� �����Ͻʴϱ�?";

		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "����ô�") return false;
			if (data.dict["���ź��"] == "��������")
			{
				data.dict["���ź��"] = "���������� �Ͼ";
				return true;
			}
			else
				return false;
		};

		{
			EventSelectItemMaker s(e, "���Ű��� ������쿡 �Ҹ��� ǰ�����ϴ�.");
			s->content =
				"��ü�� ������ �й��� �ϴ� ���ſ� ���� ���ſ����� �޾Ұ�, ���� ������ �ǰų� �ɷ��� ��ĥ �� �ִ� �ڸ��� ������ ��������ϴ�.\n\
�ܱ���-\n\
�����+";
			s->CanRun = [&](Gamedata& data) {
				return data.player.res.diplo >= 1;
			};

			s->Effect = [&](Gamedata& data) {
				data.dict["���ź��"] = "�����Ǳ�";
				data.player.res.milli += 2;
				data.player.res.diplo -= 1;
			};
		}
		{
			EventSelectItemMaker s(e, "���̸��� ������ ���� ���ſ��� ������ �޾��⶧���Դϴ�.");
			s->content =
				"������ �� �ϴ� ���ߺδ� ���� ��ȣ�ϴ� ���� �ϰ� �־��µ� \n\
�׶� ���� ������ �起���� �峭��� �кҷ� ���ߺ��� ������ �¿������ϴ�.\n\
�ܱ���-\n\
�����+";

			s->CanRun = [&](Gamedata& data) {
				return (data.player.res.diplo >= 2);
			};

			s->Effect = [&](Gamedata& data) {
				data.dict["���ź��"] = "�����Ǳ�";
				data.player.res.milli += 2;
				data.player.res.diplo -= 2;
			};
		}
		{
			EventSelectItemMaker s(e, "���� �̼����� ���� ���ſ��� ���� �´� ����� �߻��Ͽ��� �����Դϴ�.");
			s->content =
				"������ ���ų����� ������ �����µ� ���屺�� �̼����� ���� ���ſ��� �����ϴ�.\n\
�̶� ���� ������ ���屺�� �Ƿ��� ������ٸ� �̼����� ���� ������ �Ǿ����ϴ�.\n\
�ܱ���-\n\
�����+";

			s->CanRun = [&](Gamedata& data) {
				return data.player.res.diplo >= 2;
			};

			s->Effect = [&](Gamedata& data) {
				data.dict["���ź��"] = "�����Ǳ�";
				data.player.res.milli += 2;
				data.player.res.diplo -= 2;
			};
		}
	}

}
